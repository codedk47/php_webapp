#include "php_webapp.h"


ZEND_FUNCTION(cache_add)
{

	RETURN_TRUE;
}
ZEND_FUNCTION(cache_get)
{

	RETURN_TRUE;
}
const zend_function_entry webapp_functions[] = {
	ZEND_FE(cache_add, NULL)
	ZEND_FE(cache_get, NULL)
	ZEND_FE_END
};
ZEND_MINIT_FUNCTION(webapp)
{
	zend_class_entry *ce_sxe = zend_hash_str_find_ptr(CG(class_table), ZEND_STRL("simplexmlelement"));
	zend_class_entry *ce_sql = zend_hash_str_find_ptr(CG(class_table), ZEND_STRL("mysqli"));
	if (ce_sxe == NULL || ce_sql == NULL)
	{
		return FAILURE;
	}
	
	zend_class_entry ce_webapp_htt;
	INIT_CLASS_ENTRY(ce_webapp_htt, "webapp_htt", webapp_htt_fe);
	webapp_htt_ce = zend_register_internal_class_ex(&ce_webapp_htt, ce_sxe TSRMLS_CC);
	webapp_htt_ce->ce_flags |= ZEND_ACC_PUBLIC;

	zend_class_entry ce_webapp_sql;
	INIT_CLASS_ENTRY(ce_webapp_sql, "webapp_htt", webapp_sql_fe);
	webapp_sql_ce = zend_register_internal_class_ex(&ce_webapp_sql, ce_sql TSRMLS_CC);
	webapp_sql_ce->ce_flags |= ZEND_ACC_PUBLIC;

	return SUCCESS;
}
ZEND_GINIT_FUNCTION(webapp)
{
	webapp_globals->qqqqq= 1;
}
zend_module_dep webapp_dep[] = {
	ZEND_MOD_REQUIRED("SimpleXML")
	ZEND_MOD_REQUIRED("mysqli")
	{NULL,NULL,NULL}
};
zend_module_entry webapp_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	webapp_dep,
	"WebApp",
	webapp_functions,//functions
	ZEND_MINIT(webapp),
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,//version
	ZEND_MODULE_GLOBALS(webapp),
	ZEND_GINIT(webapp),
	NULL,
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};
ZEND_GET_MODULE(webapp)