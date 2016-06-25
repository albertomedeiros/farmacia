<?php
/**
 * Arquivo que conterá as validações do módulo
 * 
 */
module_load_include('inc', 'amigos', 'amigos.db');

/**
 * Método que irá atualizar o usuário para seguir/desseguir algúem
 * 
 * @throws Exception
 */
function api_seguir_amigo(){
    
    // Recuperando o post
    $arrDados = $_POST;
    
    // Caso seja atualizar notícia
    if(!empty($arrDados["uid"]) && !empty($arrDados["acao"])){
        
        global $user;
        
        $strMensagem = "";
        
        // Lendo o usuário da base
        $user = user_load($user->uid);
        
        $intUID = (int) base64_decode($arrDados["uid"]);
        $strAcao = (string) base64_decode($arrDados["acao"]);
        
        // Caso a ação for pra seguir
        if($strAcao == "seguir"){
            // seto o id do usuário para seguir
            $user->field_amigos_2["und"][]["uid"] = (string) $intUID;
            
            $strMensagem = t("Seguindo com sucesso!");
        }else{
            // Percorrendo os amigos para excluir o usuário
            foreach($user->field_amigos_2[key($user->field_amigos_2)] as $strChave => $arrValor){
                
                // Caso o usuário seja igual ao pesquisado removo do objeto
                if($intUID == $arrValor["uid"]){
                    unset ($user->field_amigos_2[key($user->field_amigos_2)][$strChave]);
                }
            }
            
            $strMensagem = t("Deixou de seguir com sucesso!");
        }
        try {
            // salvando a alteração
            user_save($user);
        } catch (Exception $exc) {
            $strMensagem = t("Ocorreu um erro, favor tentar novamente!");
        }






        return $strMensagem;
    }else{
        throw new Exception("Erro: valores incorretos");
    }
    
}


function api_getAtividades(){
    
    
    global $user;
    
    // Blocos de quatro notícia com imagens e duas notícias sem
    $objViewsAtividade = views_get_view('mensagens');
    $objViewsAtividade->set_display('block_2');
    
    // Caso o usuário acessado não seja o usuário corrente
    if($user->uid != arg(1)){
        $objViewsAtividade->args = array(arg(1));
    }else{
        $user = user_load($user->uid);
        
        $strIdUsuários = $user->uid;
        
        if(!empty($user->field_amigos_2)){
            foreach($user->field_amigos_2[key($user->field_amigos_2)] as $arrAmigos){
                $strIdUsuários .= "," . $arrAmigos["uid"];
            }
        }
        
        
        // Caso o usuário seja o usuário corrente
        $objViewsAtividade->args = array($strIdUsuários);
    }
    
    
    // Executando a views
    $objViewsAtividade->execute();

    // Renderizando o conteúdo
    print $objViewsAtividade->render('block_2');
    
}

/**
 * Pego o usuário que estou acessando seja ele atual ou logado
 * 
 * @global type $user
 * @return int
 */
function getUIDUserAtual(){
    
    global $user;
    
    $intUid = $user->uid;
    // Caso o usuário acessado não seja o usuário corrente
    if($user->uid != arg(1))
        $intUid = arg(1);
    
   return $intUid;     
}

function api_solicitar_participacao(){
    
    // Recuperando o nid
    $arg2 = arg(1);
    
    global $user;
    
    // Lendo o usuário da base
    $objUser = user_load($user->uid);
    
    // Id na notícia
    $intNid = (int) base64_decode($arg2);
    
    $bulAtualizar = true;
    
    // Caso o usuário já possua grupos
    if(!empty($objUser->field_grupos)){
        
        foreach ($objUser->field_grupos["und"] as $arrNid) {
            if($intNid == $arrNid["nid"]){
                $bulAtualizar = false;
            }
        }
        // Validando se o usuário já pediu pra participar do grupo
        if($bulAtualizar){
            $objUser->field_grupos["und"][]["nid"] = (string) $intNid;
        }else{
            throw new Exception("Solicitação foi enviada para aprovação do administrador.");
        }
        
    }else{
        $objUser->field_grupos["und"][0]["nid"] = $intNid;
    }
    
    // Caso não tenha nenhum erro
    if($bulAtualizar){
        field_attach_update("user", $objUser);
    }
}

//função para tirar os usuários dos grupos quando solicitado
function api_sair_grupo(){
    
        // Recuperando o nid
        $arg2 = arg(1);
        
        global $user;
    
        // Lendo o usuário da base
        $objUser = user_load($user->uid);

        // Id na notícia
        $intNid = (int) base64_decode($arg2);
        
        retirar_nid_array_grupos($user->uid, $intNid);
        
        if(!empty($objUser->field_grupos)){
            
            //procurando a chave correspondente ao uid do usuário que deseja sair do evento
            $key_node = array_search(array('uid'=> $uid_user), $objUser->field_grupos['und']);
            
            //retirando o uid do array de participantes do evento
            unset($objUser->field_grupos['und'][$key_node]);
            $objUser->field_grupos['und'] = array_values($objUser->field_grupos['und']);
            
            //verificando se o array de participantes está vazio. Se estiver, zerando o array pai.
            if(empty($objUser->field_grupos['und'])){
                $objUser->field_grupos = array();
            }
            
        }
        
        // Salvando os membros no grupo
        field_attach_update("user", $objUser);

        drupal_set_message(t("Você saiu do grupo!"), "status");
        
    
}

function api_aprovar_solicitacoes(){
    
    // Recuperando o nid
    $arg1 = arg(1);
    
    // Id na notícia
    $intNid = (int) base64_decode($arg1);
    
    $objNode = node_load($intNid);
    
    if(!empty($_POST["users"])){
        foreach($_POST["users"] as $intChave => $intValor){
            $objNode->field_membros[key($objNode->field_membros)][]["uid"] = $intValor;
        }
        
        // Salvando os membros no grupo
        field_attach_update("node", $objNode);
        
        drupal_set_message(t("Usuários aprovados com sucesso!"), "status");
    }else{
        drupal_set_message(t("Deculpe ocorreu um erro, favor tentar novamente"), "error");
    }
}
function api_participar_evento(){
    
    if(!empty($_GET)){
        // Recuperando o nid
        $arg1 = arg(1);

        $uid_user = $_GET['user'];

        // Id na notícia
        $intNid = (int) base64_decode($arg1);
        $objNode = node_load($intNid);

        if(empty($objNode->field_participantes)){
            $objNode->field_participantes['und'][0]["uid"] = $uid_user;
        }else{
            $tam = count($objNode->field_participantes['und']);
            $objNode->field_participantes['und'][$tam]["uid"] = $uid_user;
        }

        // Salvando os membros no grupo
        field_attach_update("node", $objNode);

        drupal_set_message(t("Você está participando do evento!"), "status");
    }else{
        drupal_set_message(t("Ocorreu um erro!"), "error");
    }
    
}

function api_sair_evento(){
    
    if(!empty($_GET)){
        // Recuperando o nid
        $arg1 = arg(1);

        $uid_user = $_GET['user'];
        
        // Id na notícia
        $intNid = (int) base64_decode($arg1);
        $objNode = node_load($intNid);


        if(!empty($objNode->field_participantes)){
            
            //procurando a chave correspondente ao uid do usuário que deseja sair do evento
            $key_user = array_search(array('uid'=> $uid_user), $objNode->field_participantes['und']);
            
            //retirando o uid do array de participantes do evento
            unset($objNode->field_participantes['und'][$key_user]);
            $objNode->field_participantes['und'] = array_values($objNode->field_participantes['und']);
            
            //verificando se o array de participantes está vazio. Se estiver, zerando o array pai.
            if(empty($objNode->field_participantes['und'])){
                $objNode->field_participantes = array();
            }
            
        }

        // Salvando os membros no grupo
        field_attach_update("node", $objNode);

        drupal_set_message(t("Você saiu do evento!"), "warning");
        
    }else{
        drupal_set_message(t("Ocorreu um erro!"), "error");
    }
}

function api_listar_solicitacao_pendente(){
    
    $arrForm = drupal_get_form("list_form_usuarios");
    
    // Recuperando o nid
    $arg1 = arg(1);
    
    // Setando voltar
    $strHtml .= "<div class=''><a href='/".drupal_get_path_alias('node/'.base64_decode($arg1))."'><i class='fa fa-reply '></i> Voltar para o grupo</a></div>";
    
    // Setando o formulário
    $strHtml .= drupal_render($arrForm);
    
    return $strHtml;
}

function list_form_usuarios(){
    
    // Recuperando o nid
    $arg1 = arg(1);
    
    // Id na notícia
    $intNid = (int) base64_decode($arg1);
    
    $arrObjUser = db_listar_solicitacao_pendente($intNid);
    
    
    $header = array(
        'nome' => array('data' => t('Nome')),
    );

    //Build the rows.
    $options = array();
    foreach ($arrObjUser as $objUser) {
        
        $user = user_load($objUser->uid);
        
        $strNome = (!empty($user->field_nome)) ? $user->field_nome[key($user->field_nome)][0]["value"] : $user->name ;
        
        $strUrl = drupal_get_path_alias('user/'.$objUser->uid);
        
        $options[$objUser->uid] = array(
          'nome' => "<a href='/" . $strUrl. "'>" .$strNome . " <br /><img src='" . image_style_url('thumbnail', $user->picture->uri) ."' /></a>",
        );
    }
    
    
    $form['users'] = array(
        '#type' => 'tableselect',
        '#header' => $header,
        '#options' => $options,
        '#empty' => t('Nenhum usuário pendente.'),
    );
    
    $form["aprovar"] = array(
                            "#type" => "submit",
                            "#title" => t("Aprovar"),
                            "#value" => t("Aprovar"),
                            "#attributes" =>  array('class' => array('btn-success'))
                         );
    
    return $form;
}

function getGruposUsuario(&$arrOptions, $intNidGrupo){
    
    // Percorrendo os grupos
    foreach($arrOptions["#options"] as $intChave => $strValor){
        if($intChave == "_none")
            continue;
        
        // Caso o grupo não seja o grupo do usuário
        if($intNidGrupo != $intChave)
            unset($arrOptions["#options"][$intChave]);
        else
            $arrOptions["#default_value"] = $intChave;
    }
}

function getEventoUsuario(&$arrOptions, $strNid){
    
    $intNid = (int) base64_decode($strNid);
    
    // Percorrendo os grupos
    foreach($arrOptions["#options"] as $intChave => $strValor){
        if($intChave == "_none")
            continue;
        
        // Caso o grupo não seja o grupo do usuário
        if($intNid != $intChave)
            unset($arrOptions["#options"][$intChave]);
        else
            $arrOptions["#default_value"] = $intChave;
    }
}

function verifica_grupo_tem_grupo(){
    
    $verifica = views_get_view_result('verifica_usuario_tem_grupo');
    
    if(!empty($verifica)){
        $retorno = 1;
    }else{
        $retorno = 0;
    }
    
   return $retorno;
}

function retirar_nid_array_grupos($uid_user, $nid){
    
        $objNode = node_load($nid);
        
        if(!empty($objNode->field_membros)){
            
            //procurando a chave correspondente ao uid do usuário que deseja sair do evento
            $key_user = array_search(array('uid'=> $uid_user), $objNode->field_membros['und']);
            
            //retirando o uid do array de participantes do evento
            unset($objNode->field_membros['und'][$key_user]);
            $objNode->field_membros['und'] = array_values($objNode->field_membros['und']);
            
            //verificando se o array de participantes está vazio. Se estiver, zerando o array pai.
            if(empty($objNode->field_membros['und'])){
                $objNode->field_membros = array();
            }
            
        }
        
        // Salvando os membros no grupo
        field_attach_update("node", $objNode);
}


function get_amigos_by_user(){
    
    $uid = arg(1);
    
    $obj_user = user_load($uid);
    $arr_amigos = $obj_user->field_amigos_2['und'];
    $uids_amigos = '';
    $tam_arr = count($arr_amigos);
    
    foreach ($arr_amigos as $key => $value) {
        if($tam_arr == 1){
           $uids_amigos = $value['uid'];
        }elseif ($key != $tam_arr-1) {
           $uids_amigos.= $value['uid'].','; 
        }else{
           $uids_amigos.= $value['uid'];
        }
    }
    
return $uids_amigos;
    
}

function get_amigos_by_user_logado(){
    
    global $user;
    
    $obj_user = user_load($user->uid);
    $arr_amigos = $obj_user->field_amigos_2['und'];
    $uids_amigos = '';
    $tam_arr = count($arr_amigos);
    
    foreach ($arr_amigos as $key => $value) {
        if($tam_arr == 1){
           $uids_amigos = $value['uid'];
        }elseif ($key != $tam_arr-1) {
           $uids_amigos.= $value['uid'].','; 
        }else{
           $uids_amigos.= $value['uid'];
        }
    }
    
    return $uids_amigos;
}


function get_uids_prox_eventos(){
    
    global $user;
    
    $uids_amigos = get_amigos_by_user_logado();
    
    if(!empty($uids_amigos)){
        $retorno = $uids_amigos . ','.$user->uid;
    }else{
        $retorno = $uids_amigos;
    }
    
    return $retorno;
    
}

function get_nums_nodes_by_tipo($tipo){
    
$query = new EntityFieldQuery();
$query->entityCondition('entity_type', 'node') // grab nodes
->entityCondition('bundle', $tipo) // filter by blog type
->propertyCondition('status', 1) // filter by published
->count(); // count

$result = $query->execute();

return $result;
}

function get_nums_comentarios(){
    
$query = new EntityFieldQuery();
$query->entityCondition('entity_type', 'comment') // grab nodes
->count(); // count

$result = $query->execute();

return $result;
}