<?php
/**
 * @file
 * bizreview_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function bizreview_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'about';
  $context->description = 'Layout of the About page';
  $context->tag = 'pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/56' => 'node/56',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-26' => array(
          'module' => 'block',
          'delta' => '26',
          'region' => 'full_width',
          'weight' => '-10',
        ),
        'views-testimonial-block' => array(
          'module' => 'views',
          'delta' => 'testimonial-block',
          'region' => 'content_bottom_first',
          'weight' => '-10',
        ),
        'block-25' => array(
          'module' => 'block',
          'delta' => '25',
          'region' => 'content_bottom_second',
          'weight' => '-10',
        ),
        'block-7' => array(
          'module' => 'block',
          'delta' => '7',
          'region' => 'image_background',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of the About page');
  t('pages');
  $export['about'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'advertise';
  $context->description = 'Layout of the Advertise page';
  $context->tag = 'pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/70' => 'node/70',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-28' => array(
          'module' => 'block',
          'delta' => '28',
          'region' => 'full_width',
          'weight' => '-10',
        ),
        'block-24' => array(
          'module' => 'block',
          'delta' => '24',
          'region' => 'content_bottom_first',
          'weight' => '-10',
        ),
        'block-12' => array(
          'module' => 'block',
          'delta' => '12',
          'region' => 'content_bottom_third',
          'weight' => '-10',
        ),
        'views-testimonial-block' => array(
          'module' => 'views',
          'delta' => 'testimonial-block',
          'region' => 'image_background',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of the Advertise page');
  t('pages');
  $export['advertise'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog-classic';
  $context->description = 'Layout of Blog Classic style';
  $context->tag = 'blog';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news-classic' => 'news-classic',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'views-list_business-block_2' => array(
          'module' => 'views',
          'delta' => 'list_business-block_2',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of Blog Classic style');
  t('blog');
  $export['blog-classic'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog-detail';
  $context->description = 'Layout of Blog Node detail';
  $context->tag = 'blog';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'views-list_business-block_2' => array(
          'module' => 'views',
          'delta' => 'list_business-block_2',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of Blog Node detail');
  t('blog');
  $export['blog-detail'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog-modern';
  $context->description = 'Layout of Blog Modern style';
  $context->tag = 'blog';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news' => 'news',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of Blog Modern style');
  t('blog');
  $export['blog-modern'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'business-detail';
  $context->description = 'Layout of Business node detail';
  $context->tag = 'business';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'business' => 'business',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-list_business-block_1' => array(
          'module' => 'views',
          'delta' => 'list_business-block_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'authorcontact-0' => array(
          'module' => 'authorcontact',
          'delta' => '0',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of Business node detail');
  t('business');
  $export['business-detail'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'categories';
  $context->description = 'Layout of each category';
  $context->tag = 'pages';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'business_category' => 'business_category',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-categories-block_3' => array(
          'module' => 'views',
          'delta' => 'categories-block_3',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of each category');
  t('pages');
  $export['categories'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'contact';
  $context->description = 'Layout of Contact page';
  $context->tag = 'pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contact' => 'contact',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-32' => array(
          'module' => 'block',
          'delta' => '32',
          'region' => 'full_width',
          'weight' => '-10',
        ),
        'block-21' => array(
          'module' => 'block',
          'delta' => '21',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-12' => array(
          'module' => 'block',
          'delta' => '12',
          'region' => 'content_bottom_first',
          'weight' => '-10',
        ),
        'block-20' => array(
          'module' => 'block',
          'delta' => '20',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of Contact page');
  t('pages');
  $export['contact'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'faqs';
  $context->description = 'Layout of the FAQs page';
  $context->tag = 'pages';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'faq' => 'faq',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of the FAQs page');
  t('pages');
  $export['faqs'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'forum';
  $context->description = 'Layout of the Forum';
  $context->tag = 'pages';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'forum' => 'forum',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'forum' => 'forum',
        'forums/general-discussion' => 'forums/general-discussion',
        'forums/city-nightlife' => 'forums/city-nightlife',
        'forums/household-care' => 'forums/household-care',
        'forums/sport-and-beauty' => 'forums/sport-and-beauty',
        'forums/food-lovers' => 'forums/food-lovers',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-forum_recent_topics-block' => array(
          'module' => 'views',
          'delta' => 'forum_recent_topics-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-forum_recent_comments-block' => array(
          'module' => 'views',
          'delta' => 'forum_recent_comments-block',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of the Forum');
  t('pages');
  $export['forum'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home-classic';
  $context->description = 'Layout of the Home Classic page';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/19' => 'node/19',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-slideshow-block' => array(
          'module' => 'views',
          'delta' => 'slideshow-block',
          'region' => 'full_width',
          'weight' => '-10',
        ),
        'views-list_business-block_5' => array(
          'module' => 'views',
          'delta' => 'list_business-block_5',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-reviews-block_1' => array(
          'module' => 'views',
          'delta' => 'reviews-block_1',
          'region' => 'content',
          'weight' => '2',
        ),
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'block-11' => array(
          'module' => 'block',
          'delta' => '11',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'views-list_business-block_2' => array(
          'module' => 'views',
          'delta' => 'list_business-block_2',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of the Home Classic page');
  t('home');
  $export['home-classic'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home-default';
  $context->description = 'Layout of Home Default';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'reviews' => 'reviews',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-slideshow-block_1' => array(
          'module' => 'views',
          'delta' => 'slideshow-block_1',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'block-16' => array(
          'module' => 'block',
          'delta' => '16',
          'region' => 'preface_second',
          'weight' => '-10',
        ),
        'views-category_restaurant-block_1' => array(
          'module' => 'views',
          'delta' => 'category_restaurant-block_1',
          'region' => 'content_top_second',
          'weight' => '-10',
        ),
        'views-category_automotive-block_1' => array(
          'module' => 'views',
          'delta' => 'category_automotive-block_1',
          'region' => 'content_top_second',
          'weight' => '-9',
        ),
        'views-category_spa-block_1' => array(
          'module' => 'views',
          'delta' => 'category_spa-block_1',
          'region' => 'content_top_second',
          'weight' => '-8',
        ),
        'views-category_nightlife-block_1' => array(
          'module' => 'views',
          'delta' => 'category_nightlife-block_1',
          'region' => 'content_top_second',
          'weight' => '-7',
        ),
        'views-category_shopping-block_1' => array(
          'module' => 'views',
          'delta' => 'category_shopping-block_1',
          'region' => 'content_top_second',
          'weight' => '-6',
        ),
        'views-category_travel-block_1' => array(
          'module' => 'views',
          'delta' => 'category_travel-block_1',
          'region' => 'content_top_second',
          'weight' => '-5',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'image_background_top',
          'weight' => '-10',
        ),
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-11' => array(
          'module' => 'block',
          'delta' => '11',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-member-block' => array(
          'module' => 'views',
          'delta' => 'member-block',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of Home Default');
  t('home');
  $export['home-default'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home-landing-page';
  $context->description = 'Layout of the Home Landing page';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/45' => 'node/45',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-map_list_business-block' => array(
          'module' => 'views',
          'delta' => 'map_list_business-block',
          'region' => 'full_width',
          'weight' => '-10',
        ),
        'views-categories-block_1' => array(
          'module' => 'views',
          'delta' => 'categories-block_1',
          'region' => 'color_background',
          'weight' => '-10',
        ),
        'views-list_business-block_3' => array(
          'module' => 'views',
          'delta' => 'list_business-block_3',
          'region' => 'content_bottom_first',
          'weight' => '-9',
        ),
        'views-events-block_1' => array(
          'module' => 'views',
          'delta' => 'events-block_1',
          'region' => 'content_bottom_second',
          'weight' => '-10',
        ),
        'block-31' => array(
          'module' => 'block',
          'delta' => '31',
          'region' => 'content_bottom_third',
          'weight' => '-8',
        ),
        'block-30' => array(
          'module' => 'block',
          'delta' => '30',
          'region' => 'content_bottom_fourth',
          'weight' => '-10',
        ),
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'content_bottom_fifth',
          'weight' => '-10',
        ),
        'views-testimonial-block' => array(
          'module' => 'views',
          'delta' => 'testimonial-block',
          'region' => 'image_background',
          'weight' => '-10',
        ),
        'block-7' => array(
          'module' => 'block',
          'delta' => '7',
          'region' => 'image_background_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of the Home Landing page');
  t('home');
  $export['home-landing-page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'map-layers';
  $context->description = 'Layout of the Map layer demo page';
  $context->tag = 'pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/43' => 'node/43',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'leaflet_demo-leaflet_maps' => array(
          'module' => 'leaflet_demo',
          'delta' => 'leaflet_maps',
          'region' => 'content',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of the Map layer demo page');
  t('pages');
  $export['map-layers'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'meet-team';
  $context->description = 'Layout of the Meet our team page';
  $context->tag = 'pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/71' => 'node/71',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-27' => array(
          'module' => 'block',
          'delta' => '27',
          'region' => 'full_width',
          'weight' => '-10',
        ),
        'views-meet_our_team-block_1' => array(
          'module' => 'views',
          'delta' => 'meet_our_team-block_1',
          'region' => 'content_bottom_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of the Meet our team page');
  t('pages');
  $export['meet-team'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'register';
  $context->description = 'Layout of the Register page';
  $context->tag = 'pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/register' => 'user/register',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of the Register page');
  t('pages');
  $export['register'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search-block';
  $context->description = 'Positions of the Search block';
  $context->tag = 'elements';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'reviews' => 'reviews',
        'home-classic' => 'home-classic',
        'node/45' => 'node/45',
        'list-business-map' => 'list-business-map',
      ),
    ),
    'taxonomy_term' => array(
      'values' => array(
        'business_category' => 'business_category',
        'location' => 'location',
        'tags' => 'tags',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-map_list_business-page_1' => array(
          'module' => 'views',
          'delta' => '-exp-map_list_business-page_1',
          'region' => 'search',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Positions of the Search block');
  t('elements');
  $export['search-block'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'submit';
  $context->description = 'Layout of Submit page';
  $context->tag = 'pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/40' => 'node/40',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-29' => array(
          'module' => 'block',
          'delta' => '29',
          'region' => 'full_width',
          'weight' => '-10',
        ),
        'block-23' => array(
          'module' => 'block',
          'delta' => '23',
          'region' => 'content_bottom_first',
          'weight' => '-10',
        ),
        'block-12' => array(
          'module' => 'block',
          'delta' => '12',
          'region' => 'content_bottom_third',
          'weight' => '-10',
        ),
        'block-14' => array(
          'module' => 'block',
          'delta' => '14',
          'region' => 'image_background',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout of Submit page');
  t('pages');
  $export['submit'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_profile';
  $context->description = '';
  $context->tag = 'elements';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-list_business-block_2' => array(
          'module' => 'views',
          'delta' => 'list_business-block_2',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('elements');
  $export['user_profile'] = $context;

  return $export;
}
