#include "php_webapp.h"

ZEND_METHOD(webapp, cache_add)
{
	RETURN_TRUE;
}
ZEND_METHOD(webapp, cache_get)
{
	RETURN_TRUE;
}
const zend_function_entry webapp_fe[] = {
	ZEND_ABSTRACT_ME(webapp, __construct, NULL)
	ZEND_ME(webapp, cache_add, NULL, ZEND_ACC_STATIC | ZEND_ACC_PUBLIC)
	ZEND_ME(webapp, cache_get, NULL, ZEND_ACC_STATIC | ZEND_ACC_PUBLIC)
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
	
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "webapp_htt", webapp_htt_fe);
	webapp_htt_ce = zend_register_internal_class_ex(&ce, ce_sxe);
	webapp_htt_ce->ce_flags |= ZEND_ACC_PUBLIC;

	INIT_CLASS_ENTRY(ce, "webapp_orm", webapp_orm_fe);
	webapp_htt_ce = zend_register_internal_class_ex(&ce, ce_sql);
	webapp_htt_ce->ce_flags |= ZEND_ACC_PUBLIC;

	INIT_CLASS_ENTRY(ce, "webapp_gd2", webapp_gd2_fe);
	webapp_gd2_ce = zend_register_internal_class(&ce);
	webapp_gd2_ce->ce_flags |= ZEND_ACC_PUBLIC;

	INIT_CLASS_ENTRY(ce, "wa", webapp_fe);
	webapp_ce = zend_register_internal_class(&ce);
	webapp_ce->ce_flags |= ZEND_ACC_FINAL | ZEND_ACC_ABSTRACT;

	return SUCCESS;
}
ZEND_MINFO_FUNCTION(webapp)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "WebApp", "enabled");
	php_info_print_table_row(2, "Author", "ZERONETA");
	php_info_print_table_row(2, "Version", PHP_WEBAPP_VERSION);
	php_info_print_table_end();
	DISPLAY_INI_ENTRIES();
}
ZEND_GINIT_FUNCTION(webapp)
{
	webapp_globals->q = 1;
}
zend_module_dep webapp_dep[] = {
	ZEND_MOD_REQUIRED("SimpleXML")
	ZEND_MOD_REQUIRED("mysqli")
	//ZEND_MOD_REQUIRED("gd2")
	{NULL,NULL,NULL}
};
zend_module_entry webapp_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	webapp_dep,
	"WebApp",
	NULL,//functions
	ZEND_MINIT(webapp),
	NULL,
	NULL,
	NULL,
	ZEND_MINFO(webapp),
	PHP_WEBAPP_VERSION,//version
	ZEND_MODULE_GLOBALS(webapp),
	ZEND_GINIT(webapp),
	NULL,
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};
ZEND_GET_MODULE(webapp)