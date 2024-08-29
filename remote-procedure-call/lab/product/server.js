/** Product API
 *
 * This program is a service which handles operations on a Product database. It
 * should expose an API which allows clients to create and view products in an
 * imaginary online store. Updating and deleting existing records are out of
 * scope for this lab.
 *
 * The purpose of the program is to demonstrate building applications using the
 * gRPC framework. Its service definition can be found in 'product.proto'.
 */

import logger from './logger/index.js';
import { get, query, insert } from './db/index.js';

// Some examples using the database driver and logger for reference. Feel free
// to comment or delete them.

const id = insert({ keyA: 'valA' });

insert({ keyB: 'valC', keyC: 'valE' });
insert({ keyA: 'valC', keyD: 'valE' });
insert({ id: 7, keyA: 'valC', keyD: 'valE' });

const record = get(id);

logger.info("record #%d: %O", id, record);
logger.info("query for keyA=valA: %O", query('keyA', 'valA'));
logger.info("query for objects having keyA: %O", query('keyA', null));
