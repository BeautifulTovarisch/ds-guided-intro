/** Product API
 *
 * This program is a service which handles operations on a Product database.
 * The purpose of the program is to demonstrate building applications using the
 * gRPC framework.
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
