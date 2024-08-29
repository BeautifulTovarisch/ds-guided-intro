// This application is a service which handles the payment operations for an
// online store. This service should specify an API which allows payments to
// be recorded in a database for a given product.
//
// The purpose of this application is to demonstrate building services with the
// gRPC framework.
package main

import (
	"github.com/beautifultovarisch/rpclab/payments/internal/db"
	"github.com/beautifultovarisch/rpclab/payments/internal/logger"
)

func main() {
	// The following statements are examples using the db and logger packages.
	// feel free to remove or comment these lines when implementing your service.
	logger.Debug("a debug log")
	logger.Info("an info log")

	rows, err := db.DB.Query("SELECT COUNT(*) FROM payment")
	if err != nil {
		logger.Error("error counting number of payments: %v", err)

		return
	}

	defer rows.Close()
}
