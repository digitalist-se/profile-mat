


var MatApp = angular.module('Mat', ['ngTouch', 'ngSanitize']);
  var filterTags = [];

  MatApp.controller('MatController', function ($scope, $http) {

    var resturantsArray = [],
    tagsArrayn = [];

    updateResturants();

    function updateResturants() {

      $http.jsonp('ajax/resturants?&callback=JSON_CALLBACK')
        .success(function(data) {

          // Get resturants and add to array
          angular.forEach(data, function(value, key) {
            resturantsArray.push(value);
          });

          $scope.resturants = resturantsArray;

          var tagsArrayn = [];

          // Get tags and add to array
          angular.forEach($scope.resturants, function(value, key) {
            angular.forEach($scope.resturants[key].tags, function(val, ke) {
              if(tagsArrayn.indexOf(val.namn)==-1) {
                tagsArrayn.push(val.namn);
              }

            });
          });

          $scope.tags = tagsArrayn;

          // Push in the distance to the array
          for (var i = 0; i < $scope.resturants.length; i++) {

            var selecetedResturantLat = $scope.resturants[i].field_latitude.und[0].value,
            selecetedResturantLong = $scope.resturants[i].field_longitude.und[0].value,
            selecetedResturantDistance = getDistance(selecetedResturantLat, selecetedResturantLong);

            $scope.resturants[i].distance = Math.floor(selecetedResturantDistance);

          }

        });
      }

    // Active Resturant
    $scope.SelectResturant = function(index) {

      for (var i = 0; i < $scope.resturants.length; i++) {
        if ($scope.resturants[i]["nid"] === index) {
          var activeResturant = $scope.resturants[i],
          tagsArray = [];

          $scope.selectedResturantTitle = activeResturant.title;
          $scope.selectedNid = activeResturant["nid"];
          $scope.selectedResturantBody = activeResturant.body.und[0].value;

          angular.forEach(activeResturant.tags, function(value, key) {
            tagsArray.push(value.namn);
          });

          $scope.selectedResturantTags = tagsArray;

          createMap(activeResturant.field_latitude.und[0].value,activeResturant.field_longitude.und[0].value);
        }
      }

    };

    $scope.addActive = function(){
        $scope.class = "active-slide";
    };

    $scope.removeActive = function(){
        $scope.class = "";
    };

    $scope.randomize = function() {
      var random = $scope.resturants[Math.floor(Math.random() * $scope.resturants.length)];
      while (random.title == $scope.selectedResturantTitle) {
        random = $scope.resturants[Math.floor(Math.random() * $scope.resturants.length)];
      }
      $scope.SelectResturant(random["nid"]);
      $scope.class = "active-slide";
    };

    $scope.activeFilters = [];

    $scope.activeTags = function(item) {

      if(filterTags.length === 0) {
        filterTags.push(item);
      } else {
          // Add to array if dont exist else remove
          if(filterTags.indexOf(item) === -1) {
            filterTags.push(item);
          } else {
            filterTags.splice(filterTags.indexOf(item), 1);
          }

      }

      $scope.activeFilters = filterTags;
    }


  });


MatApp.filter('myFilter', function () {

    return function(tasks, tags) {
        return tasks.filter(function(task) {

          if(tags.length === 0) {
            for (var i in task.tags) {

                    return true;

            }
          }

          else {
            for (var i in task.tags) {
                if (tags.indexOf(task.tags[i].namn) != -1) {
                    return true;
                }
            }
          }


            return false;

        });
    };

});


function createMap(lat,lng) {
  map = new GMaps({
    el: '#map',
    lat: lat,
    lng: lng,
    panControl: false,
    streetViewControl: false,
    mapTypeControl: false,
    overviewMapControl: false
  });

  map.addMarker({
    lat: lat,
    lng: lng
  });

}

var currentLat, currentLong;

var options = {
  enableHighAccuracy: true,
  timeout: 5000,
  maximumAge: 0
};

function success(pos) {
  var crd = pos.coords;
  currentLat = crd.latitude;
  currentLong = crd.longitude;
};

function error(err) {
  console.warn('ERROR(' + err.code + '): ' + err.message);
};

navigator.geolocation.getCurrentPosition(success, error, options);


var rad = function (x) {
  return x * Math.PI / 180;
};

var getDistance = function (r1,r2) {

  var my1 = 59.314389,
  my2 = 18.054348;

  if(typeof currentLat === 'number') {
    my1 = currentLat;
    my2 = currentLong;
  }

  var R = 6378137,
  dLat = rad(r1 - my1)
  dLong = rad(r2 - my2),
  a = Math.sin(dLat / 2) * Math.sin(dLat / 2) + Math.cos(rad(my1)) * Math.cos(rad(r1)) * Math.sin(dLong / 2) * Math.sin(dLong / 2),
  c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a)),
  d = R * c;
  return d; // returns the distance in meter
};




(function($) {


}(jQuery));
