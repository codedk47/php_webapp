#ifndef WEBAPP_HTT_H
#define WEBAPP_HTT_H
#ifndef PHP_WEBAPP_H
#include "php_webapp.h"
#endif//PHP_WEBAPP_H

zend_class_entry *webapp_htt_ce;
ZEND_METHOD(webapp_htt, add);
static const zend_function_entry webapp_htt_fe[] = {
	ZEND_ME(webapp_htt, add, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_FINAL)


	ZEND_FE_END
};

#endif//WEBAPP_HTT_H