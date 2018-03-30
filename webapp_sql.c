#include "php_webapp.h"

ZEND_METHOD(webapp_sql, add)
{
	zend_string *q = NULL, *w = NULL;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(q)
		Z_PARAM_STR(w)
	ZEND_PARSE_PARAMETERS_END();



}
