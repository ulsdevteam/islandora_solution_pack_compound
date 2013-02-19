<?php

function theme_islandora_compound_prev_next($variables) {
  $output = '<div class="islandora-compound-prev-next">';
  $output .= '<h3>' . t('Part of: ') . check_plain($variables['parent_label']) . ' (' . $variables['child_count'] . ' '
    . t('objects') . ') ';

  if ($variables['parent_url']) {
    $output .= l(t('manage parent'), $variables['parent_url']);
  }
  $output .= '</h3>';

  if (!empty($variables['previous_pid'])) {
    $output .= l(t('Previous'), 'islandora/object/' . $variables['previous_pid']);
  }
  if (!empty($variables['previous_pid']) && !empty($variables['next_pid'])) {
    $output .= ' | ';
  }
  if (!empty($variables['next_pid'])) {
    $output .= l(t('Next'), 'islandora/object/' . $variables['next_pid']);
  }

  if ($variables['child_count'] > 1) {
    $output .= '<div class="islandora-compound-thumbs">';
    foreach ($variables['siblings'] AS $sibling) {
      $output .= l(
        theme_image(
          array(
            'path' => 'islandora/object/' . $sibling . '/datastream/TN/view',
            'attributes' => array(),
          )
        ),
        'islandora/object/' . $sibling,
        array('html' => TRUE)
      );
    }
    $output .= '</div>';
  }

  $output .= '</div>';

  return $output;
}