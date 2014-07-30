<?php


$plugin = array(
  'single' => TRUE,
  'title' => t('Resturants list'),
  'description' => t('Resturants list.'),
  'category' => t('Mat'),
  'edit form' => 'resturants_list_content_type_edit_form',
  'render callback' => 'resturants_list_content_type_render',
);

/**
 * Render the custom content type.
 */
function resturants_list_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('resturants_list', array('apa' => "aapa"));
  return $block;
}

/**
 * Returns an edit form for custom type settings.
 */
function resturants_list_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function resturants_list_content_type_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
