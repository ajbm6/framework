
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


/**
 * MongoDB driver.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db_Driver_Mongodb) {

	ZEPHIR_REGISTER_CLASS(Ice\\Db\\Driver, Mongodb, ice, db_driver_mongodb, ice_db_driver_mongodb_method_entry, 0);

	zend_declare_property_string(ice_db_driver_mongodb_ce, SL("id"), "_id", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_db_driver_mongodb_ce, SL("type"), "NOSQL", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_mongodb_ce, SL("error"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_mongodb_ce, SL("client"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_mongodb_ce, SL("lastInsertId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_db_driver_mongodb_ce TSRMLS_CC, 1, ice_db_dbinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Db_Driver_Mongodb, getId) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "id");

}

PHP_METHOD(Ice_Db_Driver_Mongodb, getType) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "type");

}

PHP_METHOD(Ice_Db_Driver_Mongodb, getClient) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "client");

}

PHP_METHOD(Ice_Db_Driver_Mongodb, getLastInsertId) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "lastInsertId");

}

/**
 * Instantiate mongo connection.
 *
 * @param string dsn
 * @param string dbname
 * @param array options
 */
PHP_METHOD(Ice_Db_Driver_Mongodb, __construct) {

	zend_class_entry *_6$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *dsn_param = NULL, *dbname_param = NULL, *options_param = NULL, client, _0, _1, _2, _3, _4$$3, _5$$3, _7$$3;
	zval dsn, dbname;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&dbname);
	ZVAL_UNDEF(&client);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &dsn_param, &dbname_param, &options_param);

	zephir_get_strval(&dsn, dsn_param);
	if (!dbname_param) {
		ZEPHIR_INIT_VAR(&dbname);
		ZVAL_STRING(&dbname, "");
	} else {
		zephir_get_strval(&dbname, dbname_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "mongodb");
	ZEPHIR_CALL_FUNCTION(&_1, "phpversion", NULL, 72, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "1.2.0alpha1");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ">=");
	ZEPHIR_CALL_FUNCTION(&_3, "version_compare", NULL, 73, &_1, &_0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_INIT_VAR(&client);
		ZVAL_STRING(&client, "MongoDB\\Client");
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_fetch_safe_class(&_5$$3, &client);
		_6$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_5$$3), Z_STRLEN_P(&_5$$3), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_4$$3, _6$$3);
		if (zephir_has_constructor(&_4$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 0, &dsn, &options);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_7$$3, &_4$$3, "selectdatabase", NULL, 0, &dbname);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("client"), &_7$$3);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Version of `mongodb` extension must be 1.2.0alpha1 or higher", "ice/db/driver/mongodb.zep", 41);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the id value.
 *
 * @param string id
 * @return object
 */
PHP_METHOD(Ice_Db_Driver_Mongodb, getIdValue) {

	zephir_nts_static zend_class_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL;
	zval id;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&id);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("MongoDB\\BSON\\ObjectID"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &id);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * Get a date time object.
 *
 * @param mixed value
 * @param boolean model
 * @return object
 */
PHP_METHOD(Ice_Db_Driver_Mongodb, getDateTime) {

	zephir_nts_static zend_class_entry *_1$$4 = NULL;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, *model = NULL, model_sub, __$null, __$false, date;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&date);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &value, &model);

	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!model) {
		model = &model_sub;
		model = &__$false;
	}


	_0 = Z_TYPE_P(value) == IS_OBJECT;
	if (_0) {
		_0 = zephir_is_instance_of(value, SL("MongoDB\\BSON\\UTCDateTime") TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CPY_WRT(&date, value);
	} else {
		ZEPHIR_INIT_NVAR(&date);
		if (!_1$$4) {
		_1$$4 = zephir_fetch_class_str_ex(SL("MongoDB\\BSON\\UTCDateTime"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&date, _1$$4);
		if (zephir_has_constructor(&date TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &date, "__construct", NULL, 0, value);
			zephir_check_call_status();
		}
	}
	if (zephir_is_true(model)) {
		RETURN_CCTOR(date);
	}
	ZEPHIR_RETURN_CALL_METHOD(&date, "todatetime", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Find one document that match criteria.
 *
 * @param string from Collection name
 * @param mixed filters Criteria
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 * @return Arr
 */
PHP_METHOD(Ice_Db_Driver_Mongodb, findOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval options, fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, result, _0, _1, _2;
	zval from;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
		zephir_get_arrval(&fields, fields_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 1);
	zephir_array_update_string(&options, SL("limit"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, 0, &from, filters, &options, &fields);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_fast_count_int(&result TSRMLS_CC)) {
		object_init_ex(&_1, ice_arr_ce);
		ZEPHIR_CALL_FUNCTION(&_2, "current", NULL, 74, &result);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 5, &_2);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	RETURN_CCTOR(_1);

}

/**
 * Find all documents that match criteria.
 *
 * <pre><code>
 *  $db->find("users", array("a" => 1, "b" => "q"));
 *  $db->find("users", array("age" => array(">" => 33)));
 *  $db->find("users", array("OR" => array(array("a" => 1), array("b" => 2))));
 * </code></pre>
 *
 * @param string from Collection name
 * @param mixed filters Criteria
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 * @return Arr
 */
PHP_METHOD(Ice_Db_Driver_Mongodb, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval options, fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, result;
	zval from;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
		zephir_get_arrval(&fields, fields_param);
	}


	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, 0, &from, filters, &options, &fields);
	zephir_check_call_status();
	object_init_ex(return_value, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 5, &result);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * SELECT document(s) that match criteria.
 *
 * @param string from Collection name
 * @param mixed filters Criteria
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 */
PHP_METHOD(Ice_Db_Driver_Mongodb, select) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval options, fields, _10;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, filtered, collection, result, _0, _9, _1$$4, _2$$7, _3$$7, _4$$9, _5$$10, _6$$11, _7$$11, _8$$11;
	zval from;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
		zephir_get_arrval(&fields, fields_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_gettype(&_0, filters TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(&_0, "object")) {
			if (zephir_is_instance_of(filters, SL("MongoDB\\BSON\\ObjectID") TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(&filtered);
				zephir_create_array(&filtered, 1, 0 TSRMLS_CC);
				ZEPHIR_OBS_VAR(&_1$$4);
				zephir_read_property(&_1$$4, this_ptr, SL("id"), PH_NOISY_CC);
				zephir_array_update_zval(&filtered, &_1$$4, filters, PH_COPY);
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Object must be an ObjectID instance", "ice/db/driver/mongodb.zep", 141);
				return;
			}
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "array")) {
			ZEPHIR_CPY_WRT(&filtered, filters);
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "integer") || ZEPHIR_IS_STRING(&_0, "string")) {
			ZEPHIR_INIT_NVAR(&filtered);
			zephir_create_array(&filtered, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&_2$$7);
			zephir_read_property(&_2$$7, this_ptr, SL("id"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_3$$7, this_ptr, "getidvalue", NULL, 0, filters);
			zephir_check_call_status();
			zephir_array_update_zval(&filtered, &_2$$7, &_3$$7, PH_COPY);
			break;
		}
		ZEPHIR_INIT_NVAR(&filtered);
		array_init(&filtered);
		break;
	} while(0);

	if (zephir_array_isset_string(&options, SL("order"))) {
		zephir_array_fetch_string(&_4$$9, &options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/mongodb.zep", 160 TSRMLS_CC);
		zephir_array_update_string(&options, SL("sort"), &_4$$9, PH_COPY | PH_SEPARATE);
		zephir_array_unset_string(&options, SL("order"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(&options, SL("offset"))) {
		zephir_array_fetch_string(&_5$$10, &options, SL("offset"), PH_NOISY | PH_READONLY, "ice/db/driver/mongodb.zep", 165 TSRMLS_CC);
		zephir_array_update_string(&options, SL("skip"), &_5$$10, PH_COPY | PH_SEPARATE);
		zephir_array_unset_string(&options, SL("offset"), PH_SEPARATE);
	}
	if (zephir_fast_count_int(&fields TSRMLS_CC)) {
		ZEPHIR_CALL_FUNCTION(&_6$$11, "array_flip", NULL, 9, &fields);
		zephir_check_call_status();
		ZVAL_LONG(&_7$$11, 1);
		ZEPHIR_CALL_FUNCTION(&_8$$11, "array_fill_keys", NULL, 7, &_6$$11, &_7$$11);
		zephir_check_call_status();
		zephir_array_update_string(&options, SL("projection"), &_8$$11, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_9, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&collection, &_9, "selectcollection", NULL, 0, &from);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &collection, "find", NULL, 0, &filtered, &options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_10, SL("root"), SL("array"));
	add_assoc_stringl_ex(&_10, SL("document"), SL("array"));
	add_assoc_stringl_ex(&_10, SL("array"), SL("array"));
	ZEPHIR_CALL_METHOD(NULL, &result, "settypemap", NULL, 0, &_10);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("iterator_to_array", NULL, 75, &result);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * INSERT document into collection.
 *
 * @param string from Collection name
 * @param array fields Fields to insert, keys are the column names
 */
PHP_METHOD(Ice_Db_Driver_Mongodb, insert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval *from_param = NULL, *fields_param = NULL, collection, result, _0, _1, _2, _3;
	zval from;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
		zephir_get_arrval(&fields, fields_param);
	}


	zephir_read_property(&_0, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&collection, &_0, "selectcollection", NULL, 0, &from);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &collection, "insertone", NULL, 0, &fields);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &result, "getinsertedid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("lastInsertId"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CALL_METHOD(&_3, &result, "getinsertedcount", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	RETURN_CCTOR(_2);

}

/**
 * UPDATE documents in the collection.
 *
 * @param string from Collection name
 * @param mixed filters Criteria
 * @param array fields Fields to update, keys are the column names
 */
PHP_METHOD(Ice_Db_Driver_Mongodb, update) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval fields, _1;
	zval *from_param = NULL, *filters = NULL, filters_sub, *fields_param = NULL, collection, result, _0, _2, _3;
	zval from;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &from_param, &filters, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
		zephir_get_arrval(&fields, fields_param);
	}


	zephir_read_property(&_0, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&collection, &_0, "selectcollection", NULL, 0, &from);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("$set"), &fields, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&result, &collection, "updatemany", NULL, 0, filters, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CALL_METHOD(&_3, &result, "getmatchedcount", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	RETURN_CCTOR(_2);

}

/**
 * Remove documents from the collection.
 *
 * @param string from Collection name
 * @param mixed filters Criteria
 */
PHP_METHOD(Ice_Db_Driver_Mongodb, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *from_param = NULL, *filters = NULL, filters_sub, collection, result, _0, _1, _2;
	zval from;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &filters);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}


	zephir_read_property(&_0, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&collection, &_0, "selectcollection", NULL, 0, &from);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &collection, "deletemany", NULL, 0, filters);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, &result, "getdeletedcount", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	RETURN_CCTOR(_1);

}

/**
 * Get an error message.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Db_Driver_Mongodb, getError) {

	zval error, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_string_fetch(&error, &_0, SL("err"), 1);
	RETURN_CTORW(error);

}

