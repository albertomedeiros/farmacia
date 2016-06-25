<?php
/**
 * Irá conter as validações do módulo
 * 
 * @author Alberto Medeiros
 */
module_load_include('inc', 'cadastro', 'cadastro.db');

/**
 * Irá validar e persistir os dados
 * @throws Exception
 */
function cadastro_api(){
    // Recuperando as informações
    $strNome        = (string) $_POST["strNome"];
    $strSobreNome   = (string) $_POST["strSobreNome"];
    // validações
    if(empty(trim($strNome)))        throw new Exception("O nome não foi informado");
    if(empty(trim($strSobreNome)))        throw new Exception("O sobre nome não foi informado");
    // Criando o array a ser persistido
    $arrDados = array("nome" => $strNome, "sobrenome" => $strSobreNome);
    // Cadastrando na base
    cadastro_db($arrDados);
}
