<?php
/**
 * @file
 * cart_import_ical.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function cart_import_ical_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'cart_feeds_ical';
  $feeds_importer->config = array(
    'name' => 'Cart ical',
    'description' => 'Import google shared calendar',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'DateiCalFeedsParser',
      'config' => array(
        'indefinite_count' => '52',
        'until_not_utc' => FALSE,
        'skip_days' => NULL,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'UID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'SUMMARY',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'DTSTART',
            'target' => 'field_cart_date:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'DTEND',
            'target' => 'field_cart_date:end',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'LOCATION',
            'target' => 'field_cart_venue',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'DESCRIPTION',
            'target' => 'body',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'cart_exhibition',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['cart_feeds_ical'] = $feeds_importer;

  return $export;
}
