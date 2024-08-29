/** Product Database
 *
 * This module simulates a database for the purposes of maintaining the state
 * of the system. Its implementation details are not part of the lab, and it is
 * provided purely for convenience. The interface supports retrieval by object
 * id and range query and does not provide operations to update existing objects.
 * This roughly correlates to an immutable key-value or document store.
 *
 * Objects' identifiers are strictly positive monotonically increasing integers
 * and are assigned automatically on insert. Providing your own identifier in
 * the object's body has no effect.
 *
 * USAGE:
 *  import {get, query, insert} from 'db';
 *
 *  const id = insert({ keyA: 'valA', keyB: 'valB' });
 *  insert({ keyA: 'valC', keyD: 'valE' });
 *
 *  get(id);
 *  // { keyA: 'valA', keyB: 'valB' }
 *
 *  query('keyA', 'valA');
 *  [ { id: 1, keyA: 'valA', keyB: 'valB' } ]
 *
 *  query('keyA', null);
 *  [ { id: 1, keyA: 'valA', keyB: 'valB' },
 *    { id: 2, keyA: 'valC', keyD: 'valE' } ]
 */

let counter = 1;

let database = {};

// get retrieves the record corresponding to [id] from the database or NULL if
// not present.
export const get = id => database[id];

const filterRecords = (key, value) => ([_, record]) =>
    (key in record) && ((value === null) || (record[key] === value));

// query returns all records which satisfiy the predicate [key]=[value]. If NULL
// is provided as [value], the query will return all records that contain [key].
export const query = (key, value) =>
  Object.entries(database)
    .filter(filterRecords(key, value))
    .map(([_, record]) => record);

// insert adds [obj] to the database and returns its automatically assigned id.
export const insert = obj => {
  const { id, ...data } = obj;

  database = {...database, [counter]: { id: counter, ...data } };

  return counter++;
};
