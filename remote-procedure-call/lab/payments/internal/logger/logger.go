// package logger implements a basic logger. Its implementation is not part of
// the lab, and is provided purely for convenience. You may modify this package
// in any way you see fit.
//
// Logs are output with the following format:
//
//	[timestamp] LEVEL MESSAGE
//
// USAGE:
//
//	import "github.com/beautifultovarisch/rpclab/internal/logger
//
//	logger.Debug("application listening on %s:%d", Host, Port)
//	logger.Info("transaction #%d complete", txnid)
//	logger.Error("error processing request: %v", err)
package logger

import (
	"fmt"
	"log"
	"os"
)

type level uint8

const (
	DEBUG level = iota
	INFO
	WARN
	ERROR
)

func (l level) String() string {
	switch l {
	case DEBUG:
		return "DEBUG"
	case INFO:
		return "INFO"
	case WARN:
		return "WARN"
	case ERROR:
		return "ERROR"
	default:
		return "UNKNOWN"
	}
}

const flags = log.Ldate | log.Ltime | log.Lmicroseconds

var logger = log.New(os.Stdout, "", flags)

func writelog(lvl level, format string, msg ...any) {
	defer logger.SetOutput(os.Stdout)

	if lvl >= WARN {
		logger.SetOutput(os.Stderr)
	}

	output := fmt.Sprintf(format, msg...)

	log.Printf("%s %s", lvl, output)
}

// Debug outputs logs at the DEBUG level. These are usually contain information
// helpful for debugging the application.
func Debug(format string, msg ...any) {
	writelog(DEBUG, format, msg...)
}

// Info outputs logs at the INFO level. Typically this information is used to
// reason about the state of an application.
func Info(format string, msg ...any) {
	writelog(INFO, format, msg...)
}

// Warn outputs logs at the WARN level. These logs usually contain important,
// but non-urgent action items that do not interrupt the normal operation of
// the application.
func Warn(format string, msg ...any) {
	writelog(WARN, format, msg...)
}

// Error outputs logs at the ERROR level. These indicate the application has
// failed to perform some action, but is able to continue operation.
func Error(format string, msg ...any) {
	writelog(ERROR, format, msg...)
}
