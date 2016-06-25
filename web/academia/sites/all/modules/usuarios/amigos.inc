<?php
/**
 * Arquivo que conterá as pagecallback do módulo
 */

module_load_include('inc', 'amigos', 'amigos.api');

function seguir_amigo(){
    
    $bolRetorno = false;
    
    try {
        
        // Realizando a ação de seguir
        $strMensagem = api_seguir_amigo();
        
        $bolRetorno = true;
        
        $strAcaoPost = (string) base64_decode($_POST["acao"]);
        
        $strAcao = "status";
        if($strAcaoPost != "seguir")
            $strAcao = "error";
        
        
        drupal_set_message(t($strMensagem), $strAcao);
    } catch (Exception $exc) {
        $strMensagem = $exc->getMessage();
        drupal_set_message(t($exc->getMessage()), "error");
    }

    $arrRetorno = array();
    $arrRetorno["bolRetorno"] = $bolRetorno;
    $arrRetorno["strMensagem"] = $strMensagem;
    
    echo json_encode($arrRetorno);die;
}


function solicitar_participacao(){
    
    $strMensagem = t(", a solicitação foi enviada com sucesso! Ficaremos aguardando a aprovação do presidente do grupo");
    $bolErro = false;
    try {
        
        api_solicitar_participacao();
        
    } catch (Exception $exc) {
        $bolErro = true;
        $strMensagem = $exc->getMessage();
    }
    return theme("aprovacao-grupo", array("strMensagem" => $strMensagem, "bolErro" => $bolErro));
}

function sair_grupo(){
    
    api_sair_grupo();
}

function aprovar_solicitações(){
    
    try {
        
        if(!empty($_POST)){
            api_aprovar_solicitacoes();
        }
        
        return api_listar_solicitacao_pendente();
        
    } catch (Exception $exc) {}
}

function aprovar_solicitações_evento(){
    
    api_participar_evento();
}

function sair_evento(){
    
    api_sair_evento();
}