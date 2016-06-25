<?php
/**
 * Irá conter os callbacks do módulo (Controller|Roteador)
 * 
 * @author Alberto Medeiros
 */

// Incluindo os arquivos
module_load_include('inc', 'cadastro', 'cadastro.api');

function cadastro(){
    // Caso tenha POST
    if(!empty($_POST)){
        $bolRetorno = false;
        $strMensagem = "Cadastrado com sucesso!";
        try {
            // Chamo a função de validação de dados
            cadastro_api();
            // Caso dê tudo certo
            $bolRetorno = true;
        } catch (Exception $exc) {
            $strMensagem = $exc->getMessage();
        }
        // Criando a variavel de retorno
        $arrRetorno = array();
        $arrRetorno["bolRetorno"] = $bolRetorno;
        $arrRetorno["strMensagem"] = $strMensagem;
        // Printando o retorno da função
        echo json_encode($arrRetorno);die;
    }else{// Caso não retorno o tema
        return theme("cadastro");
    }
}