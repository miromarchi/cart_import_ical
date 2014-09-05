<?php
/**
 * @file
 * cart_import_ical.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cart_import_ical_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
