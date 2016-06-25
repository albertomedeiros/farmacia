<?php

/**
 * Irá conter as persistências e consulta do módulo
 * 
 * @author Alberto Medeiros
 */

/**
 * Irá cadastrar os dados informados
 * 
 * @param array $arrDados
 * @throws Exception
 */
function cadastro_db($arrDados){
    try {
        // Irá cadastrar os dados informados
        $objQuery = db_insert('cadastro')->fields($arrDados)->execute();
    } catch (Exception $exc) {
        throw new Exception($exc->getMessage());
    }
}