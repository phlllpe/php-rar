/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2004 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  |                                                                      |
  |                        **** WARNING ****                             |
  |                                                                      |
  | This module makes use of unRAR - free utility for RAR archives.      |
  | It's license states, that you MUST NOT use it's code to develop      |
  | a RAR (WinRAR) compatible archiver.                                  |
  | Please, read unRAR license for full information.                     |
  | unRAR & RAR copyrights are owned by Eugene Roshal                    |
  +----------------------------------------------------------------------+
  | Author: Antony Dovgal <tony2001@phpclub.net>                         |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_RAR_H
#define PHP_RAR_H

extern zend_module_entry rar_module_entry;
#define phpext_rar_ptr &rar_module_entry

#ifdef PHP_WIN32
#define PHP_RAR_API __declspec(dllexport)
#else
#define PHP_RAR_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(rar);
PHP_MSHUTDOWN_FUNCTION(rar);
PHP_RINIT_FUNCTION(rar);
PHP_RSHUTDOWN_FUNCTION(rar);
PHP_MINFO_FUNCTION(rar);

PHP_FUNCTION(rar_open);
PHP_FUNCTION(rar_list);
PHP_FUNCTION(rar_entry_get);
PHP_FUNCTION(rar_close);

PHP_METHOD(rarentry, extract);
PHP_METHOD(rarentry, getName);
PHP_METHOD(rarentry, getUnpackedSize);
PHP_METHOD(rarentry, getPackedSize);
PHP_METHOD(rarentry, getHostOs);
PHP_METHOD(rarentry, getFileTime);
PHP_METHOD(rarentry, getCrc);
PHP_METHOD(rarentry, getAttr);
PHP_METHOD(rarentry, getVersion);
PHP_METHOD(rarentry, getMethod);

typedef struct rar {
	int							id;
	int							entry_count;
	struct RARHeaderData		**entries;
	struct RAROpenArchiveData	*list_handle;
	struct RAROpenArchiveData	*extract_handle;
	void						*list_data;
	char						*password;
} rar_file_t;

#endif	/* PHP_RAR_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */