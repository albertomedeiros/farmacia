<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title_prefix || $title_suffix || $display_submitted || !$page): ?>
  <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($display_submitted): ?>
      <div class="submitted">
        <?php print $user_picture; ?>
        <span class="glyphicon glyphicon-calendar"></span> <?php print $submitted; ?>
      </div>
    <?php endif; ?>
  </header>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
        
        $arrValoresDias = array();
        $arrDias = array();
        foreach($node->field_horas_funcionamentos["und"] as $intChave => $arrValor){
            $objFieldColection = field_collection_item_load($arrValor["value"]);
            $objTaxonomy = taxonomy_term_load($objFieldColection->field_horario["und"][0]["tid"]);
            
            
            foreach($objFieldColection->field_dias_da_semana["und"] as $intChave => $intValor){
                $intDia = (int) $intValor["value"];
                $arrDados = array("hora"=>$objTaxonomy->name, 
                              "dia" => $intDia, 
                              "unidade"    => $objFieldColection->field_unidade["und"][0]["value"]);
                $arrValoresDias[$intDia][] = $arrDados;
            }
        }
        
        foreach($arrValoresDias as $arrValores){

        }
    ?>
  </div>

  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
    <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

</article>