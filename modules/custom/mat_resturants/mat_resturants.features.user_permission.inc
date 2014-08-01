<?php
/**
 * @file
 * mat_resturants.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mat_resturants_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create resturant content'.
  $permissions['create resturant content'] = array(
    'name' => 'create resturant content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any resturant content'.
  $permissions['edit any resturant content'] = array(
    'name' => 'edit any resturant content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own resturant content'.
  $permissions['edit own resturant content'] = array(
    'name' => 'edit own resturant content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
