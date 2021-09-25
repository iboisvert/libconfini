#!/bin/sh
#
# libconfini/dev/tests/null-byte_injection/null-byte_injection.sh
#

printf '[my_section]\r\n\r\nfoo = bar\r\nh\000\000e\000llo = wo\000\000\000\000\000rld' > null-byte_injected.conf
gcc -Wall -pedantic -std=c99 -lconfini null-byte_injection.c -O2 -o /tmp/null-byte_injection && { \
	/tmp/null-byte_injection
	rm /tmp/null-byte_injection
}
