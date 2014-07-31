<?php 

/**
 * Implements of hook_ctools_plugin_directory().
 */
function market_ctools_plugin_directory($module, $plugin){
  if ($module == 'ctools' || $module == 'panels'){
    return 'plugins/' . $plugin;
  }
}

/**
 * Implements hook_install_tasks().
 */
function market_install_tasks($install_state){
  $tasks = array(

    'mat_active_theme' => array(
      'display_name' => st('Setup Theme active'),
      'display' => FALSE,
      'type' => 'normal'
    ),
  );

    return $tasks;
}

/**
 * Activate theme.
 */

function mat_active_theme() {

 $enable = array(
    'theme_default' => 'mat',
    'admin_theme' => 'seven',
    //'zen'
  );
  theme_enable($enable);

  foreach ($enable as $var => $theme) {
    if (!is_numeric($var)) {
      variable_set($var, $theme);
    }
  }

  // Disable the default Bartik theme
  theme_disable(array('bartik'));


}