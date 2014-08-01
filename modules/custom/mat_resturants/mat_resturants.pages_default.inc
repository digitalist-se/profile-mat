<?php
/**
 * @file
 * mat_resturants.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function mat_resturants_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Resturant Edit',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'edit-page',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'edit';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main_content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e9ee5fa2-76fd-4bf6-ab53-fa85b94a14af';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5dbf7686-5b17-4c4b-837a-457412041405';
    $pane->panel = 'main_content';
    $pane->type = 'node_form_title';
    $pane->subtype = 'node_form_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'naked',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5dbf7686-5b17-4c4b-837a-457412041405';
    $display->content['new-5dbf7686-5b17-4c4b-837a-457412041405'] = $pane;
    $display->panels['main_content'][0] = 'new-5dbf7686-5b17-4c4b-837a-457412041405';
    $pane = new stdClass();
    $pane->pid = 'new-ff76daae-d7eb-474d-8ab2-e9d58f93f5e3';
    $pane->panel = 'main_content';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ff76daae-d7eb-474d-8ab2-e9d58f93f5e3';
    $display->content['new-ff76daae-d7eb-474d-8ab2-e9d58f93f5e3'] = $pane;
    $display->panels['main_content'][1] = 'new-ff76daae-d7eb-474d-8ab2-e9d58f93f5e3';
    $pane = new stdClass();
    $pane->pid = 'new-2d31173b-cf57-48f9-b6af-f5bd279a01c5';
    $pane->panel = 'main_content';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2d31173b-cf57-48f9-b6af-f5bd279a01c5';
    $display->content['new-2d31173b-cf57-48f9-b6af-f5bd279a01c5'] = $pane;
    $display->panels['main_content'][2] = 'new-2d31173b-cf57-48f9-b6af-f5bd279a01c5';
    $pane = new stdClass();
    $pane->pid = 'new-7001d956-2c74-481e-b1c4-920b686c619c';
    $pane->panel = 'main_content';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_latitude';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '7001d956-2c74-481e-b1c4-920b686c619c';
    $display->content['new-7001d956-2c74-481e-b1c4-920b686c619c'] = $pane;
    $display->panels['main_content'][3] = 'new-7001d956-2c74-481e-b1c4-920b686c619c';
    $pane = new stdClass();
    $pane->pid = 'new-9d35b160-6c9a-41bc-9c58-e692af0c0dfe';
    $pane->panel = 'main_content';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_longitude';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '9d35b160-6c9a-41bc-9c58-e692af0c0dfe';
    $display->content['new-9d35b160-6c9a-41bc-9c58-e692af0c0dfe'] = $pane;
    $display->panels['main_content'][4] = 'new-9d35b160-6c9a-41bc-9c58-e692af0c0dfe';
    $pane = new stdClass();
    $pane->pid = 'new-ac151ee1-be49-4240-9cf3-f5c70da5b567';
    $pane->panel = 'main_content';
    $pane->type = 'node_form_publishing';
    $pane->subtype = 'node_form_publishing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'ac151ee1-be49-4240-9cf3-f5c70da5b567';
    $display->content['new-ac151ee1-be49-4240-9cf3-f5c70da5b567'] = $pane;
    $display->panels['main_content'][5] = 'new-ac151ee1-be49-4240-9cf3-f5c70da5b567';
    $pane = new stdClass();
    $pane->pid = 'new-710bf789-86dc-48c6-90ca-6339b5758a57';
    $pane->panel = 'main_content';
    $pane->type = 'node_form_buttons';
    $pane->subtype = 'node_form_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '710bf789-86dc-48c6-90ca-6339b5758a57';
    $display->content['new-710bf789-86dc-48c6-90ca-6339b5758a57'] = $pane;
    $display->panels['main_content'][6] = 'new-710bf789-86dc-48c6-90ca-6339b5758a57';
    $pane = new stdClass();
    $pane->pid = 'new-832088f8-193c-4a1e-bc49-d2afc7a40697';
    $pane->panel = 'main_content';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '832088f8-193c-4a1e-bc49-d2afc7a40697';
    $display->content['new-832088f8-193c-4a1e-bc49-d2afc7a40697'] = $pane;
    $display->panels['main_content'][7] = 'new-832088f8-193c-4a1e-bc49-d2afc7a40697';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function mat_resturants_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content';
  $page->task = 'page';
  $page->admin_title = 'Content';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_content_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'frontpaged';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'main_primary' => NULL,
      'left_content' => NULL,
      'right_content' => NULL,
      'top_content' => NULL,
      'main_content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9155d9d4-fd2e-42b6-b8a5-b973f97ed80e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1bd8a8d1-8c26-4903-9bdd-bf408393cc29';
    $pane->panel = 'main_content';
    $pane->type = 'resturants_list';
    $pane->subtype = 'resturants_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'form_build_id' => 'form-Wbw9xqCpRQMnd688oqPTbP_hX8ApJD6nbVFNV-lswzU',
      'form_token' => 'n9PG0jvR5bDJFyZ-MGD04mKWz7w4GnPmIhkxWBQ-qs8',
      'form_id' => 'resturants_list_content_type_edit_form',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1bd8a8d1-8c26-4903-9bdd-bf408393cc29';
    $display->content['new-1bd8a8d1-8c26-4903-9bdd-bf408393cc29'] = $pane;
    $display->panels['main_content'][0] = 'new-1bd8a8d1-8c26-4903-9bdd-bf408393cc29';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content'] = $page;

  return $pages;

}
