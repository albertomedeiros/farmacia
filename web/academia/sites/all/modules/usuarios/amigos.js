(function($) {

    $(document).ready(function(){
        
        /**
         * Evento de click para o botão de seguir
         */
        $(".user-seguir").click( function(){
           
                var strTexto = $(this).text();
                
                // Setando texto de espera
                $(this).text("Carregando ...");
                
                $(".progress-seguir").show();
                
                console.log("foi");
                
                jQuery.post(Drupal.settings.basePath + "seguir/" + $(this).attr("rel_data_uid") + "/" + $(this).attr("rel_data_uid"), {
                    uid     : $(this).attr("rel_data_uid"),
                    acao    : $(this).attr("rel_data_uid")
                } , function(arrRetorno){
                    
                    console.log("Chegou");
                    
                    // Setando o texto anterior
                    $(this).text(strTexto);
                    
                    $(".progress-seguir").hide();
                    
                    // recarregando a página
                    window.location.reload();
                }, "json");
        });
        
    });
    
})(jQuery);