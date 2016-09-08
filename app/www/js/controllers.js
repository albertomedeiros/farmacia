angular.module('starter.controllers', [])

.controller('AppCtrl', function($scope, $ionicModal, $timeout) {

  // With the new view caching in Ionic, Controllers are only called
  // when they are recreated or on app start, instead of every page change.
  // To listen for when this page is active (for example, to refresh data),
  // listen for the $ionicView.enter event:
  //$scope.$on('$ionicView.enter', function(e) {
  //});
  // Hide the accessory bar by default (remove this to show the accessory bar above the keyboard
    // for form inputs)
    if (window.StatusBar) {
      // org.apache.cordova.statusbar required
      StatusBar.styleDefault();
    }
    
    navigator.geolocation.getCurrentPosition(function(res) {
        objGetLocation = res.coords
    }, function(err) {
      console.log("deu erro...");
      console.log(JSON.stringify(err));
    })

    if (window.StatusBar) {
      StatusBar.styleDefault();
    }
            
  // Lista de Remédios
  $scope.playlists = [
    {valor: 15.60, remedio: "Dipirona",      nome: 'Farmacia dos Pobres', id: 1 },
    {valor: 6.35,  remedio: "Dipirona",      nome: 'Big Ben', id: 2 },
    {valor: 7.4,   remedio: "Dorflex",       nome: 'Drogazil', id: 3 },
    {valor: 6.38,  remedio: "Paracetamol",   nome: 'Americanas', id: 4 },
    {valor: 13.45, remedio: "Refesnoc",      nome: 'Carrefour', id: 5 },
    {valor: 11.60, remedio: "Gripazil",      nome: 'Bom Preço', id: 6 }
  ];
  
  // Form data for the login modal
  $scope.loginData = {};

  // Create the login modal that we will use later
  $ionicModal.fromTemplateUrl('templates/login.html', {
    scope: $scope
  }).then(function(modal) {
    $scope.modal = modal;
  });

  // Triggered in the login modal to close it
  $scope.closeLogin = function() {
    $scope.modal.hide();
  };

  // Open the login modal
  $scope.login = function() {
    $scope.modal.show();
  };

  // Perform the login action when the user submits the login form
  $scope.doLogin = function() {
    console.log('Doing login', $scope.loginData);

    // Simulate a login delay. Remove this and replace with your login
    // code if using a login system
    $timeout(function() {
      $scope.closeLogin();
    }, 1000);
  };
})
.controller('PlaylistsCtrl', function($scope, $http) {
    var setIntervalGoogle = setInterval(function(){
        if(objGetLocation != null){
            strUrlGoogle = strUrlGoogle+objGetLocation.latitude+","+objGetLocation.longitude;
            window.clearInterval(setIntervalGoogle);
            // Acessando a url
            $http.get(strUrlGoogle)
            .then(function(response) {
                // Recuperando o objeto
                objEnderecoMap = response.data;
                $scope.bairro = objEnderecoMap.results[0].address_components[2].long_name
                $scope.cidade = objEnderecoMap.results[0].address_components[3].long_name
            }).catch(function (data) { });;
        }else{
            console.log("ainda não");
        }
    }, 500);
})
.controller('PlaylistCtrl', function($scope, $stateParams) {
    var intI = 0;
    for(intI = 0 ; intI < $scope.playlists.length; intI++){
        objAtual = $scope.playlists[intI];
        if($stateParams.playlistId == objAtual.id){
            $scope.objAtual = objAtual;
            console.log(objAtual);
        }        
    }
});
