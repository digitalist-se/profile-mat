<?php 

/**
 * Implements of hook_ctools_plugin_directory().
 */
function mat_ctools_plugin_directory($module, $plugin){
  if ($module == 'ctools' || $module == 'panels'){
    return 'plugins/' . $plugin;
  }
}

/**
 * Implements hook_install_tasks().
 */
function mat_install_tasks($install_state){
  $tasks = array(

    'mat_active_theme' => array(
      'display_name' => st('Setup Theme active'),
      'display' => FALSE,
      'type' => 'normal'
    ),

    'mat_add_values' => array(
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

function mat_add_values() {

  // Set frontpage
  variable_set('site_frontpage', 'home');

  $vocabulary = taxonomy_vocabulary_machine_name_load('tags');

  $terms = array(
    'Kebab',
    'Pizza',
  );

  mat_add_taxonomy_terms_recursive($terms, $vocabulary->vid);
}

function mat_add_taxonomy_terms_recursive($term_tree, $vid, $parent = NULL) {
  foreach($term_tree as $term_name => $term) {
    // Create the term
    $term_object = new stdClass();
    $term_object->vid = $vid;
    $term_object->name = is_array($term) ? $term_name : $term;
    if(isset($parent)) {
      $term_object->parent = $parent;
    }
    taxonomy_term_save($term_object);

    if(is_array($term)) {
      // Recursively call the function, passing the term id of the parent.
      mat_add_taxonomy_terms_recursive($term, $vid, $term_object->tid);
    }
  }
}