<?php
/**
 * @file
 * hr_search.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function hr_search_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'hr_current_search';
  $item->label = 'Humanitarianresponse';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => ' Filter: <span class="facetapi-active">[facetapi_results:result-count] item</span> displayed',
        'plural' => 1,
        'text_plural' => 'Filter: <span class="facetapi-active">[facetapi_results:result-count] items</span> displayed',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'div',
        'css' => 1,
        'classes' => 'current-search-filter',
        'weight' => '-48',
      ),
      'reset' => array(
        'id' => 'text',
        'label' => 'Reset',
        'text' => '<a href="/[facetapi_results:search-path]"><i class="reset"></i></a> Reset filter',
        'plural' => 1,
        'text_plural' => '<a href="/[facetapi_results:search-path]"><i class="reset"></i></a> Reset all filters',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'div',
        'css' => 1,
        'classes' => 'current-reset-filter',
        'weight' => '0',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '1',
    ),
  );
  $export['hr_current_search'] = $item;

  return $export;
}
