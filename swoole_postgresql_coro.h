/*
  +----------------------------------------------------------------------+
  | Swoole                                                               |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Zhenyu Wu  <936321732@qq.com>                                |
  +----------------------------------------------------------------------+
 */
#ifndef SWOOLE_POSTGRESQL_H_
#define SWOOLE_POSTGRESQL_H_

#include "ext/swoole/config.h"
#include "ext/swoole/php_swoole_cxx.h"
#include "config.h"

#define PHP_SWOOLE_EXT_POSTGRESQL_VERSION     "4.5.0"
#define PHP_SWOOLE_EXT_POSTGRESQL_VERSION_ID  40500

#if SWOOLE_API_VERSION_ID != 0x202003a
#error "Ext version does not match the Swoole version"
#endif

#ifdef __APPLE__
#include <libpq-fe.h>
#endif

#ifdef __linux__
#include <postgresql/libpq-fe.h>
#endif

enum query_type
{
    NORMAL_QUERY, META_DATA, PREPARE
};

typedef struct _php_pgsql_object
{
    PGconn *conn;
    swSocket *socket;
    PGresult *result;
    zval *object;
    zval _object;
    ConnStatusType status;
    enum query_type request_type;
    int row;
    bool connected;
    double timeout;
    swTimer_node *timer;
} pg_object;

#define PGSQL_ASSOC           1<<0
#define PGSQL_NUM             1<<1
#define PGSQL_BOTH            (PGSQL_ASSOC|PGSQL_NUM)

#endif
