<?php

/**
 * @file
 * Definition of views_handler_field_accesslog_path.
 */

/**
 * Provide simple renderer that turns a URL into a clickable link.
 *
 * @ingroup views_field_handlers
 */
class statistics_views_handler_field_accesslog_path extends views_handler_field {

  /**
   * Override init function to provide generic option to link to node.
   */
  public function init(&$view, &$options) {
    parent::init($view, $options);
    if (!empty($this->options['display_as_link'])) {
      $this->additional_fields['path'] = 'path';
    }
  }

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['display_as_link'] = array('default' => TRUE, 'bool' => TRUE);

    return $options;
  }

  /**
   * Provide link to the page being visited.
   */
  public function options_form(&$form, &$form_state) {
    $form['display_as_link'] = array(
      '#title' => t('Display as link'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['display_as_link']),
    );
    parent::options_form($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }

  /**
   * {@inheritdoc}
   */
  public function render_link($data, $values) {
    if (!empty($this->options['display_as_link'])) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = $this->get_value($values, 'path');
      $this->options['alter']['html'] = TRUE;
    }

    return $data;
  }

}
