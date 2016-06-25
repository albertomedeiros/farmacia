<?php
/**
 * @file
 * bizreview_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bizreview_features_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_purchase_options|node|business|form';
  $field_group->group_name = 'group_purchase_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'business';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Purchase options',
    'weight' => '19',
    'children' => array(
      0 => 'commerce_node_notification',
      1 => 'commerce_node_checkout',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-purchase-options field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_purchase_options|node|business|form'] = $field_group;

  return $export;
}
