/** Logger
 *
 * This module implements a barebones logger used primarily for debugging
 * purposes. Its implementation is not part of the lab, and is included purely
 * for convenience.
 *
 * USAGE:
 *  import logger from 'logger';
 *
 *  logger.debug("application listening on %s:%d", HOST, PORT);
 *  logger.info("this is an informational message");
 *  logger.warn("this is a warning message: %s", warning);
 *  logger.error("an error has occurred: %s", err);
 *
 * Logs are output in the following format:
 *
 *  [timestamp] LEVEL MESSAGE
 *
 * Messages are formatted according to the rules of util.format. logger.error
 * and logger.warn output to STDERR, all other methods output to STDOUT.
 */

const { Console } = console;

const logger = new Console({ stdout: process.stdout, stderr: process.stderr });

const LEVEL = {
  DEBUG: 0,
  INFO: 1,
  WARN: 2,
  ERROR: 3,
}

const levelToStr = level => {
  switch (level) {
    case LEVEL.DEBUG:
      return "DEBUG";
    case LEVEL.INFO:
      return "INFO";
    case LEVEL.WARN:
      return "WARN";
    case LEVEL.ERROR:
      return "ERROR";
    default:
      return "UNKNOWN";
  }
}

const log = (level, format, ...message) => {
  const timestamp = new Date(Date.now());
  const fmt = `[%o] %s ${format}`;

  if (level < 2) {
    return console.log(fmt, timestamp, levelToStr(level), ...message);
  }

  console.error(fmt, timestamp, levelToStr(level), ...message);
};

const debug = (format, ...message) => {
  log(LEVEL.DEBUG, format, ...message);
}

const info = (format, ...message) => {
  log(LEVEL.INFO, format, ...message);
}

const warn = (format, ...message) => {
  log(LEVEL.WARN, format, ...message);
}

const error = (format, ...message) => {
  log(LEVEL.ERROR, format, ...message);
}

export default {
  debug,
  info,
  error,
  warn
};
