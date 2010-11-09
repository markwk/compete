<?php

// $Id$

/**
 * @file
 * Admin callbacks for the Compete module.
 */

/**
 * Implementation of hook_admin_settings()
 */
function compete_admin_settings_form(&$form_state) {

  $form['compete'] = array(
    '#type' => 'textarea',
    '#title' => t('Compete Tag'),
    '#default_value' => variable_get('compete', ''),
    '#size' => 20,
    '#rows' => 7,
    '#required' => TRUE,
    '#description' => t('If you do not already have a Compete Tag, please acquire it by registering at: !link', array('!link'=>l('http://www.compete.com/user/signup','http://www.compete.com/user/signup'))),
  );

  return system_settings_form($form);
}
