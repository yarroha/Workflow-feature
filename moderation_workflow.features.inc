<?php
/**
 * @file
 * moderation_workflow.features.inc
 */

/**
 * Implements hook_views_api().
 */
function moderation_workflow_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function moderation_workflow_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_rules_link().
 */
function moderation_workflow_default_rules_link() {
  $items = array();
  $items['approve'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Approve",
      "link_type" : "token",
      "bundles" : { "article" : "article" },
      "entity_link" : 1
    },
    "name" : "approve",
    "label" : "Approve",
    "path" : "approve",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['approve_cloned'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Reject",
      "link_type" : "token",
      "bundles" : { "article" : "article" },
      "entity_link" : 1
    },
    "name" : "approve_cloned",
    "label" : "Reject",
    "path" : "reject",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['need_moderation'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Need moderation",
      "link_type" : "token",
      "bundles" : { "article" : "article" },
      "entity_link" : 1
    },
    "name" : "need_moderation",
    "label" : "Need moderation",
    "path" : "need_moderation",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  return $items;
}
