#include "php_webapp.h"

ZEND_METHOD(webapp_orm, __construct)
{
	zend_string *q = NULL;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(q)
	ZEND_PARSE_PARAMETERS_END();
}

ZEND_METHOD(webapp_orm, eq)
{
	zend_string *q = NULL;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(q)
	ZEND_PARSE_PARAMETERS_END();
}