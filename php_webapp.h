#ifndef PHP_WEBAPP_H
#define PHP_WEBAPP_H
#define PHP_WEBAPP_VERSION "1.0"
#define PHP_COMPILER_ID "VC15"

#include "php.h"
zend_module_entry webapp_module_entry;
zend_class_entry *webapp_ce;

ZEND_DECLARE_MODULE_GLOBALS(webapp);
ZEND_BEGIN_MODULE_GLOBALS(webapp)
int q;
ZEND_END_MODULE_GLOBALS(webapp)
#define WEBAPP_G(q) ZEND_MODULE_GLOBALS_ACCESSOR(webapp, q)








#include "webapp_htt.h"
#include "webapp_orm.h"
#include "webapp_gd2.h"
#endif//PHP_WEBAPP_H