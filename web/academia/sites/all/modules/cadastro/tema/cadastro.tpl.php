<?php

/**
 * Contém o form da cadastro da aplicação
 * 
 * @author Alberto Medeiros
 */

?>

<form action="" class="formCadastrar" >
    <p><label for="strNome">Nome</label>
       <input maxlength="20" size="20"  type="text" id="strNome" value="" name="strNome" /></p>
    <p><label for="SobreNome">Sobre Nome</label>
        <input  maxlength="50" size="50" type="text" id="strNome" value="" name="SobreNome" /></p>
    <input type="reset" class="btCancelar" />
    <input type="submit" class="btCadastrar" />
</form>