#include "log.h"

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

static void log_write(const char *level, const char *fmt, va_list ap)
{
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    char timestamp[32];

    strftime(timestamp,
             sizeof(timestamp),
             "%Y-%m-%d %H:%M:%S",
             tm);

    fprintf(stdout, "[%s] %-5s ", timestamp, level);
    vfprintf(stdout, fmt, ap);
    fprintf(stdout, "\n");
}

void log_info(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    log_write("INFO", fmt, ap);
    va_end(ap);
}

void log_warn(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    log_write("WARN", fmt, ap);
    va_end(ap);
}

void log_error(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    log_write("ERROR", fmt, ap);
    va_end(ap);
}

void log_debug(const char *fmt, ...)
{
#ifdef DEBUG

    va_list ap;
    va_start(ap, fmt);
    log_write("DEBUG", fmt, ap);
    va_end(ap);

#else
    (void)fmt;
#endif
}