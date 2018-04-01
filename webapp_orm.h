#ifndef WEBAPP_ORM_H
#define WEBAPP_ORM_H
#ifndef PHP_WEBAPP_H
#include "php_webapp.h"
#endif//PHP_WEBAPP_H

zend_class_entry *webapp_orm_ce;
ZEND_METHOD(webapp_orm, __construct);
ZEND_METHOD(webapp_orm, eq);
static const zend_function_entry webapp_orm_fe[] = {
	ZEND_ME(webapp_orm, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_FINAL)
	ZEND_ME(webapp_orm, eq, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_FINAL)
	ZEND_FE_END
};

#endif//WEBAPP_ORM_H