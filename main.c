#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* TODO: hash the string, to "whiten" the mac value returned */

/* converts a decimal string on stdin to a legal MAC address on stdout */
int main(int argc, const char *argv[], const char *env[])
{
	const int max_len = 256;
	char *str = alloca(max_len);
	unsigned long lmac;
	unsigned char mac[6];
	int wm;

	if (!fgets(str, max_len, stdin))
		return 0;
	lmac = strtoul(str, NULL, 10);

	for (wm = 0; wm < sizeof(mac); wm++) {
		mac[wm] = lmac;
		lmac >>= 8;
	}

	/* force unicast, locally-administered */
	mac[0] &= ~1;
	mac[0] += 2;

	for (wm = 0; wm < sizeof(mac); wm++) {
		fprintf(stdout, "%s%02x", wm == 0 ? "" : ":", mac[wm]);
	}
	fprintf(stdout, "\n");

	
	/* 1401903128120022 */
	return 0;
}

