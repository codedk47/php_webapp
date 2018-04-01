#include "php_webapp.h"

ZEND_METHOD(webapp_gd2, __construct)
{
	zend_string *x = NULL, *y = NULL;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(x)
		Z_PARAM_STR(y)
	ZEND_PARSE_PARAMETERS_END();
}