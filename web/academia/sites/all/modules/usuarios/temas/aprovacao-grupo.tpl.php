<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

global $user;
global $base_url;

$objUser = user_load($user->uid);


$strNome = (!empty($objUser->field_nome)) ? $objUser->field_nome[key($objUser->field_nome)][0]["value"] : $objUser->name ;

// Recuperando o nid
$arg2 = arg(1);
   

$intNid = (int) base64_decode($arg2);

// Lendo a notícia
$objGrupo = node_load($intNid);
?>

<div class="alert <?= (!$bolErro) ?  "alert-success" : "alert-danger" ?>">
<strong><?= $strNome ?></strong> <?= $strMensagem ?>
</div>
<p>Voltar para o Grupo <a href="<?= $base_url . "/" . drupal_get_path_alias('node/'.$objGrupo->nid) ?>"><?= $objGrupo->title ?></a></p>