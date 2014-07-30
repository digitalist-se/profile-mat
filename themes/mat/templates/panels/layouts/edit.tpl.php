<?php
/**
 * @file
 * This layout is intended to be used inside the page content pane. Thats why
 * there is not wrapper div by default.
 */
?>

<div class="container" ng-controller="MatController">
    <?php print render($content['main_content']); ?>
</div>
