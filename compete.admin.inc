<?php

// $Id: compete.admin.inc,v 1.1.2.2 2010/11/09 16:21:36 jasonrsavino Exp $

/**
 * @file
 * Admin callbacks for the Compete module.
 */

/**
 * Implements hook_admin_settings().
 */
function compete_admin_settings_form($form, &$form_state) {

  $form['compete'] = array(
    '#type' => 'textarea',
    '#title' => t('Compete Tag'),
    '#default_value' => variable_get('compete', ''),
    '#size' => 20,
    '#rows' => 7,
    '#required' => TRUE,
    '#description' => t('If you do not already have a Compete Tag, please acquire it by registering at: !link', array('!link' => l('http://www.compete.com/user/signup', 'http://www.compete.com/user/signup'))),
  );

  // Render the role overview.
  $result = db_query('SELECT * FROM {role} ORDER BY name');

  $form['roles'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Role Tracking'),
    '#collapsible' => TRUE,
    '#description' => t('Define what user roles should be tracked by Compete.'),
  );

 foreach ($result as $role) {
    // can't use empty spaces in varname
    $role_varname = $string = str_replace(' ', '_', $role->name);
    $form['roles']["compete_track_{$role_varname}"] = array(
      '#type' => 'checkbox',
      '#title' => t($role->name),
      '#default_value' => variable_get("compete_track_{$role_varname}", FALSE),
    );
  }

  return system_settings_form($form);
}
