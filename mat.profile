<?php
/**
 * @file
 * Enables modules and site configuration for a mat site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function mat_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

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



// First, we must set up an array
$viewport = array(
  '#tag' => 'meta', // The #tag is the html tag - <link />
  '#attributes' => array( // Set up an array of attributes inside the tag
    'name' => 'viewport',
    'content' => 'initial-scale=1, maximum-scale=1'
  ),
);
drupal_add_html_head($viewport, 'initial_scale');

// First, we must set up an array
$web_app_capable = array(
  '#tag' => 'meta', // The #tag is the html tag - <link />
  '#attributes' => array( // Set up an array of attributes inside the tag
    'name' => 'apple-mobile-web-app-capable',
    'content' => 'yes'
  ),
);
drupal_add_html_head($web_app_capable, 'mobile_web');

$web_icon = array(
  '#tag' => 'link', // The #tag is the html tag - <link />
  '#attributes' => array( // Set up an array of attributes inside the tag
    'rel' => 'apple-touch-icon',
    'href' => 'http://kebab.webcindario.com/wp-content/themes/sliding-door/imagemenu/images/1.jpg'
  ),
);
drupal_add_html_head($web_icon, 'touch-icon');

$web_image = array(
  '#tag' => 'link', // The #tag is the html tag - <link />
  '#attributes' => array( // Set up an array of attributes inside the tag
    'rel' => 'apple-touch-startup-image',
    'href' => 'http://i.imgur.com/M1mjWi2.png'
  ),
);
drupal_add_html_head($web_image, 'touch-image');
