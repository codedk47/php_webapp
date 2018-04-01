#ifndef WEBAPP_GD2_H
#define WEBAPP_GD2_H
#ifndef PHP_WEBAPP_H
#include "php_webapp.h"
#endif//PHP_WEBAPP_H

zend_class_entry *webapp_gd2_ce;
ZEND_METHOD(webapp_gd2, __construct);
static const zend_function_entry webapp_gd2_fe[] = {
	ZEND_ME(webapp_gd2, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_FINAL)
	ZEND_FE_END
};

#endif//WEBAPP_GD2_H