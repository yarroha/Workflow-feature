<?php
/**
 * @file
 * moderation_workflow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function moderation_workflow_default_rules_configuration() {
  $items = array();
  $items['rules_demote_old_front_page_sticky_content'] = entity_import('rules_config', '{ "rules_demote_old_front_page_sticky_content" : {
      "LABEL" : "Demote old front page sticky content",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "views_bulk_operations", "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "Node", "type" : "node" } },
      "ACTION SET" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : { "view" : "workflow|page" },
            "PROVIDE" : { "entity_list" : { "node_list" : "Node list" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "node-list" ] },
            "ITEM" : { "node" : "Node" },
            "DO" : [
              { "node_make_unsticky" : { "node" : [ "node" ] } },
              { "drupal_message" : { "message" : "Removed [node:title] from the front page." } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_link_condition_approve'] = entity_import('rules_config', '{ "rules_link_condition_approve" : {
      "LABEL" : "Rules link: Approve condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } }
      ]
    }
  }');
  $items['rules_link_condition_approve_cloned'] = entity_import('rules_config', '{ "rules_link_condition_approve_cloned" : {
      "LABEL" : "Rules link: Reject condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } }
      ]
    }
  }');
  $items['rules_link_condition_need_moderation'] = entity_import('rules_config', '{ "rules_link_condition_need_moderation" : {
      "LABEL" : "Rules link: Need moderation condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "AND" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } }
      ]
    }
  }');
  $items['rules_link_set_approve'] = entity_import('rules_config', '{ "rules_link_set_approve" : {
      "LABEL" : "Rules link: Approve rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-status" ], "value" : "0" } },
              { "drupal_message" : { "message" : "Node [node:title] was approved." } }
            ],
            "LABEL" : "Approve"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_approve_cloned'] = entity_import('rules_config', '{ "rules_link_set_approve_cloned" : {
      "LABEL" : "Rules link: Reject rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-status" ], "value" : "2" } },
              { "drupal_message" : { "message" : "Node [node:title] was rejected." } }
            ],
            "LABEL" : "Reject"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_need_moderation'] = entity_import('rules_config', '{ "rules_link_set_need_moderation" : {
      "LABEL" : "Rules link: Need moderation rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-status" ], "value" : "1" } },
              { "drupal_message" : { "message" : "Node [node:title] status was changed to the \\"Need moderation\\"." } }
            ],
            "LABEL" : "Need moderation"
          }
        }
      ]
    }
  }');
  $items['rules_node_type'] = entity_import('rules_config', '{ "rules_node_type" : {
      "LABEL" : "Node type",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "Node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } }
      ]
    }
  }');
  return $items;
}
