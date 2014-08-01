<?php
/**
 * Shared Theme functions.
 * Specific theme functions (function specific etc.) is placed in modules.
 */

/**
 * Implements of hook_html_head_alter().
 */
function mat_html_head_alter(&$head_elements) {
  // change the default meta content-type tag to the shorter HTML5 version.
  $head_elements['system_meta_content_type']['#attributes'] = array(
      'charset' => 'utf-8',
  );
}

/**
 * Implements template_preprocess_html().
 */
function mat_preprocess_html(&$vars) {
  $themePath = drupal_get_path('theme', 'mat');

  // Viewport.
  $meta_viewport = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'content' => 'initial-scale=1, maximum-scale=1',
      'name' => 'viewport',
    )
  );
  drupal_add_html_head($meta_viewport, 'meta_viewport');

  // First, we must set up an array
  $web_app_capable = array(
    '#tag' => 'meta', // The #tag is the html tag - <link />
    '#attributes' => array(// Set up an array of attributes inside the tag
      'name' => 'apple-mobile-web-app-capable',
      'content' => 'yes'
    ),
  );
  drupal_add_html_head($web_app_capable, 'mobile_web');

  $web_icon = array(
    '#tag' => 'link', // The #tag is the html tag - <link />
    '#attributes' => array(// Set up an array of attributes inside the tag
      'rel' => 'apple-touch-icon',
      'href' => 'http://kebab.webcindario.com/wp-content/themes/sliding-door/imagemenu/images/1.jpg'
    ),
  );
  drupal_add_html_head($web_icon, 'touch-icon');

  $web_image = array(
    '#tag' => 'link', // The #tag is the html tag - <link />
    '#attributes' => array(// Set up an array of attributes inside the tag
      'rel' => 'apple-touch-startup-image',
      'href' => 'http://i.imgur.com/M1mjWi2.png'
    ),
  );
  drupal_add_html_head($web_image, 'touch-image');
}
