<?php

/**
 * @file
 * Scheduler rules functions.
 */

/**
 * Implements hook_rules_action_info().
 */
function dkan_harvest_dashboard_rules_action_info() {
  // These actions can be added when building a reaction rule. Use a $defaults
  // array to avoid duplication.
  $defaults = array(
    'parameter' => array(
      'node' => array(
        'type' => 'node',
        // 'label' is shown as fieldset title after adding action.
        'label' => t('The data source to be harvested'),
        // 'description' is shown beneath the label during add/edit.
        'description' => t('This can be a source node object or node id'),
      ),
    ),
    'group' => t('DKAN Harvest'),
  );

  $actions['dkan_harvest_dashboard_harvest_cache_action'] = array('label' => t('Cache Source')) + $defaults;
  $actions['dkan_harvest_dashboard_harvest_migrate_action'] = array('label' => t('Migrate Source')) + $defaults;
  $actions['dkan_harvest_dashboard_harvest_cache_migrate_action'] = array('label' => t('Harvest (Cache and Migrate) Source')) + $defaults;

  return $actions;
}

/**
 * Cache the Harvest Source.
 *
 * @param $node The Harvest Source to be cached
 */
function dkan_harvest_dashboard_harvest_cache_action($harvest_source_node) {
  $harvestSource = HarvestSource::getHarvestSourceFromNode($harvest_source_node);
  dkan_harvest_cache_sources(array($harvestSource));
}

/**
 * Migrate the Harvest Source.
 *
 * @param $node The Harvest Source to be migrated
 */
function dkan_harvest_dashboard_harvest_migrate_action($harvest_source_node) {
  $harvestSource = HarvestSource::getHarvestSourceFromNode($harvest_source_node);
  dkan_harvest_migrate_sources(array($harvestSource));
}

/**
 * Cache and migrate the Harvest Source.
 *
 * @param $node The Harvest Source to be cached and migrated
 */
function dkan_harvest_dashboard_harvest_cache_migrate_action($harvest_source_node) {
  $harvestSource = HarvestSource::getHarvestSourceFromNode($harvest_source_node);
  dkan_harvest_cache_sources(array($harvestSource));
  dkan_harvest_migrate_sources(array($harvestSource));
}
