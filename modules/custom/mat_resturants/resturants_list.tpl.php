
<div class="left-content">
  <nav class="settings">

    <ul>
      <li ng-click="add()" class="add_button"><a href="/node/add/resturant"></a></li>
      <li ng-click="randomize();" class="random_trigger"></li>
      <li ng-click="isOpen = !isOpen" ng-init="isOpen = false" class="tags_trigger"></li>
    </ul>

    <div class="tags" ng-class="{'open-tags': isOpen}">
      <ul>
          <li ng-repeat="taggen in tags" class="tag" ng-class="{'button': !isActive, 'active-tag': isActive}"
         ng-init="isActive = false"
         ng-click="isActive = !isActive; activeTags(taggen)">{{taggen}}</li>
      <ul>
    </div>

  </nav>

  <div class="resturants">
    <ul class="resturant" ng-repeat="resturant in resturants | orderBy:'distance':reverse | myFilter:activeFilters" ng-click="SelectResturant(resturant.nid); addActive()">
      <h2>{{resturant.title}}</h2>
      <span>{{resturant.distance}} m</span>
    </ul>
  </div>
</div>

<div class="right-content" ng-swipe-right="removeActive()" ng-class="class">
  <div ng-click="removeActive()" class="mob-exit"></div>
  <h1>{{selectedResturantTitle}}</h1>
  <p ng-bind-html="selectedResturantBody"></p>
  <span ng-repeat="tag in selectedResturantTags">{{tag}}, </span>

  <div id="map"></div>

  <a href="/node/{{selectedNid}}/edit">Edit</a>

</div>
