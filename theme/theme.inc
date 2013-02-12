<?php

function theme_islandora_compound_prev_next($variables) {
  $output = '<div class="islandora-compound-prev-next">';
  $output .= '<h3>' . check_plain($variables['parent_label']) . '</h3>';

  if (!empty($variables['previous_pid'])) {
    $output .= l(t('Previous'), 'islandora/object/' . $variables['previous_pid']);
  }
  if (!empty($variables['previous_pid']) && !empty($variables['next_pid'])) {
    $output .= ' | ';
  }
  if (!empty($variables['next_pid'])) {
    $output .= l(t('Next'), 'islandora/object/' . $variables['next_pid']);
  }

  $output .= '</div>';

  return $output;
}