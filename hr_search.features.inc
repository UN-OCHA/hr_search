<?php
/**
 * @file
 * hr_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function hr_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "hr_solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_dataset_categories:parents_all" : "field_dataset_categories:parents_all",
              "field_ind_cross_tagging:parents_all" : "field_ind_cross_tagging:parents_all",
              "field_ind_domain:parents_all" : "field_ind_domain:parents_all"
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "title_field" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_ind_disaggregation" : true,
              "field_ind_unit_desc" : true,
              "field_ind_denominator" : true,
              "field_ind_numerator" : true,
              "field_ind_code" : true,
              "field_ind_threshold" : true,
              "field_ind_general_guidance" : true,
              "field_ind_guidance_baseline" : true,
              "field_ind_guidance_phases" : true,
              "field_ind_data_sources" : true,
              "field_ind_comments" : true,
              "body:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_ind_disaggregation" : true,
              "field_ind_unit_desc" : true,
              "field_ind_denominator" : true,
              "field_ind_numerator" : true,
              "field_ind_code" : true,
              "field_ind_threshold" : true,
              "field_ind_general_guidance" : true,
              "field_ind_guidance_baseline" : true,
              "field_ind_guidance_phases" : true,
              "field_ind_data_sources" : true,
              "field_ind_comments" : true,
              "body:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_ind_disaggregation" : true,
              "field_ind_unit_desc" : true,
              "field_ind_denominator" : true,
              "field_ind_numerator" : true,
              "field_ind_code" : true,
              "field_ind_threshold" : true,
              "field_ind_general_guidance" : true,
              "field_ind_guidance_baseline" : true,
              "field_ind_guidance_phases" : true,
              "field_ind_data_sources" : true,
              "field_ind_comments" : true,
              "body:value" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_ind_disaggregation" : true,
              "field_ind_unit_desc" : true,
              "field_ind_denominator" : true,
              "field_ind_numerator" : true,
              "field_ind_code" : true,
              "field_ind_threshold" : true,
              "field_ind_general_guidance" : true,
              "field_ind_guidance_baseline" : true,
              "field_ind_guidance_phases" : true,
              "field_ind_data_sources" : true,
              "field_ind_comments" : true,
              "body:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "language" : { "type" : "string" },
        "url" : { "type" : "uri" },
        "status" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "title_field" : { "type" : "text" },
        "field_job_title" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_location" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_organizations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_themes" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_locations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_coordination_hubs" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_bundles" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "og_group_ref" : { "type" : "integer", "entity_type" : "node" },
        "field_first_name" : { "type" : "text" },
        "field_disasters" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_last_name" : { "type" : "text" },
        "field_funding_methods" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_sector" : { "type" : "integer", "entity_type" : "node" },
        "field_sectors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_funding_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_publication_date" : { "type" : "date" },
        "field_document_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_ind_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ind_response" : { "type" : "boolean" },
        "field_ind_standards" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ind_domain" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ind_guidance_phases" : { "type" : "text", "boost" : "0.5" },
        "field_ind_disaggregation" : { "type" : "text", "boost" : "0.5" },
        "field_ind_data_sources" : { "type" : "text", "boost" : "0.5" },
        "field_ind_threshold" : { "type" : "text", "boost" : "0.5" },
        "field_ind_comments" : { "type" : "text", "boost" : "0.5" },
        "field_ind_unit_desc" : { "type" : "text", "boost" : "0.5" },
        "field_ind_cross_tagging" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ind_guidance_baseline" : { "type" : "text", "boost" : "0.5" },
        "field_ind_key" : { "type" : "boolean" },
        "field_ind_numerator" : { "type" : "text", "boost" : "0.5" },
        "field_ind_general_guidance" : { "type" : "text", "boost" : "0.5" },
        "field_ind_code" : { "type" : "string" },
        "field_ind_unit" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_ind_denominator" : { "type" : "text", "boost" : "0.5" },
        "field_event_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_dataset_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dataset_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ds_date" : { "type" : "date" },
        "search_api_language" : { "type" : "string" },
        "body:value" : { "type" : "text" },
        "field_languages:safe_value" : { "type" : "list\\u003Cstring\\u003E" },
        "field_ds_datasources:value" : { "type" : "text" },
        "field_ds_summary:value" : { "type" : "text" },
        "field_terms_of_use:value" : { "type" : "text" },
        "field_ds_abstract:value" : { "type" : "text" },
        "field_ds_recent_changes:value" : { "type" : "text" },
        "field_ds_instructions:value" : { "type" : "text" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function hr_search_default_search_api_server() {
  $items = array();
  $items['hr_solr'] = entity_import('search_api_server', '{
    "name" : "Solr",
    "machine_name" : "hr_solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "scheme" : "http",
      "host" : "dev.humanitarianresponse.info",
      "port" : "8080",
      "path" : "\\/solr\\/dev1",
      "http_user" : "root",
      "http_pass" : "root",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "AUTO"
    },
    "enabled" : "1"
  }');
  return $items;
}
