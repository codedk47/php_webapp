#ifndef WEBAPP_SQL_H
#define WEBAPP_SQL_H
#ifndef PHP_WEBAPP_H
#include "php_webapp.h"
#endif//PHP_WEBAPP_H

zend_class_entry *webapp_sql_ce;
ZEND_METHOD(webapp_sql, add);
static const zend_function_entry webapp_sql_fe[] = {
	ZEND_ME(webapp_sql, add, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_FINAL)


	ZEND_FE_END
};

#endif//WEBAPP_HTT_H