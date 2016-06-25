<?php

/**
 * Arquivo que conterá a persistencia dos dados da entidade
 * 
 * @author Alberto Medeiros 
 */

/**
 * Método que irá listar os contatos feito no site da prefeitura
 * 
 * @param array $header
 * @return ArrayObject 
 */
function db_buscar_recife_responde(array $header, array $arrDadosBusca){
    try {
        // query base
        $query = db_select('webform_views_recife_responde', 'rr')->extend('PagerDefault')->limit(50);

        // condições da pesquisa
        if(!empty($arrDadosBusca["secretaria"]))
            $query->condition('rr.secretaria___orgao',$arrDadosBusca["secretaria"]);
        
        if(!empty($arrDadosBusca["bairro"]))
            $query->condition('rr.onde_voce_mora_no_recife',$arrDadosBusca["bairro"]);
        
        if(!empty($arrDadosBusca["email"]))
            $query->condition('rr.e_mail',$arrDadosBusca["email"]);
        
        if(!empty($arrDadosBusca["nome"]))
            $query->condition('rr.nome',"%".$arrDadosBusca["nome"]."%", "LIKE");
        
        $query->condition('rr.submitted', $arrDadosBusca["data_inicial"], ">=");
        $query->condition('rr.submitted', $arrDadosBusca["data_final"], "<=");
        
        $query->fields("rr");
        
        //extend TableSort
        $query->extend('TableSort')
        ->orderByHeader($header);
//        ->fields ('bal');

//        echo $query;
        // execute
        return $query->execute()->fetchAll();
    } catch (Exception $exc) {
        throw new Exception($exc->getMessage());
    }
}


function db_listar_solicitacao_pendente($intNid){
    
    $intNid = (int) $intNid;
    
    $strSql = "SELECT
                uid, name, field_grupos_nid
              FROM
                users u
              INNER JOIN
                field_data_field_grupos AS gu
                  ON u.uid = gu.entity_id AND gu.entity_type = 'user' and gu.field_grupos_nid = $intNid

              where
                uid not in(
                        select
                          m.field_membros_uid
                        from node n
                          inner join field_data_field_membros m on n.nid = m.entity_id
                        where n.nid = $intNid
                     )";
    
    $objSql = db_query($strSql)->fetchAll();
    
    return $objSql;
}