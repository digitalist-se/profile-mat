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

    'mat_add_taxonomies' => array(
      'display_name' => st('Setup add taxonomies'),
      'display' => FALSE,
      'type' => 'normal'
    ),

    'mat_add_nodes' => array(
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

    // Set frontpage
  variable_set('site_frontpage', 'home');

}

function mat_add_taxonomies() {

  $vocabulary = taxonomy_vocabulary_machine_name_load('tags');

  $terms = array(
    'Kebab',
    'Pizza',
    'Lunch',
    'Sallad',

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

function mat_add_nodes(){

  $term_kebab = taxonomy_get_term_by_name('Kebab');
  $term_pizza = taxonomy_get_term_by_name('Pizza');
  $term_sallad = taxonomy_get_term_by_name('Sallad');

  $values = array(
    'type' => 'resturant',
    'uid' => 1,
    'status' => 1,
  );
  $entity = entity_create('node', $values);
  $wrapper = entity_metadata_wrapper('node', $entity);
  $wrapper->title->set(t("Palmyra"));
  $wrapper->body->set(array('value' => "Fett nice kebab bre Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum ac blandit enim. Aenean quis nulla "));
  $wrapper->field_tags->set(array($term_kebab[1]->tid));
  $wrapper->field_latitude->set("59.297196");
  $wrapper->field_longitude->set("18.050202");
  $wrapper->save();

  $entity = entity_create('node', $values);
  $wrapper = entity_metadata_wrapper('node', $entity);
  $wrapper->title->set(t("Pane Vino"));
  $wrapper->body->set(array('value' => "God pizza och pasta men fett dyrt. men gott "));
  $wrapper->field_tags->set(array($term_pizza[1]->tid));
  $wrapper->field_latitude->set("59.317842");
  $wrapper->field_longitude->set("18.049888");
  $wrapper->save();

}
