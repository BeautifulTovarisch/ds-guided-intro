// package db provides functions that access a local sqlite database. It is not
// part of the lab, and is provided purely for convenience.
//
// A connection is automatically opened when this package is imported. If the
// database cannot be opened or created, the initialization will panic.
package db

import (
	"database/sql"

	_ "modernc.org/sqlite"
)

// DB is a connection to the payments sqlite database. It is initialized when
// the package is imported.
var DB *sql.DB

func init() {
	db, err := sql.Open("sqlite", "./payments.db")
	if err != nil {
		panic(err)
	}

	if err := db.Ping(); err != nil {
		panic(err)
	}

	DB = db
}
