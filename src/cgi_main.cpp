// cgi_main.cpp : the console / CGI entry point of gcal-cgi.exe.
//
// gcal.cpp is kept identical to gcal-jni-lib/jni/gcal.cpp, which exports the query to Java
// (Java_org_gaurabda_GCalManager_nativeGCal4Query) instead of having a main(). This file gives
// the same query a command line:
//
//   gcal-cgi.exe "q=calendar&lc=Kyiv&la=50.45010&lo=30.52340&ty=2019&tm=1&td=1&tc=31&lt=2E00&dst=3x0x5x0x10x0x5x0"
//
// The answer (XML) goes to stdout. An unknown query prints nothing and exits with 1.

#include <stdio.h>

const char *AnalyzeQueryString(const char *mQueryString, int xmlSize);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fputs("usage: gcal-cgi \"q=calendar&lc=...&la=...&lo=...&ty=...&tm=...&td=...&tc=...&lt=...\"\n", stderr);
        return 2;
    }
    const char *xml = AnalyzeQueryString(argv[1], 0);
    if (xml == NULL) {
        return 1;
    }
    fputs(xml, stdout);
    return 0;
}
