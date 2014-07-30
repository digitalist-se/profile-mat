<?php
/**
 * @file
 * mat_resturants.features.inc
 */

/**
 * Implements hook_node_info().
 */
function mat_resturants_node_info() {
  $items = array(
    'resturant' => array(
      'name' => t('Resturant'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
