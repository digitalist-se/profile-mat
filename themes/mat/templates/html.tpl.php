<!DOCTYPE html>
  <head>
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php print $styles; ?>
    <?php print $scripts; ?>
  </head>
  <body class="<?php print $classes; ?>" <?php print $attributes; ?> ng-app="Mat">
    <?php print $page; ?>
    <script type="text/javascript">
      var logged_in = <?php echo $logged_in ? 'true' : 'false'; ?>;
    </script>

  </body>
</html>
