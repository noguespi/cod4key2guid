/*

	cod4key2guid
	by pierz 06/2008
	http://www.indahax.com 

 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "md5.h"

void cod4_md5_init(md5_context *pms) {

    pms->total[0] = pms->total[1] = 0;

	pms->state[0] = 0x6F1CD602;
    pms->state[1] = 0x226C74BE;
    pms->state[2] = 0xB31C088D;
    pms->state[3] = 0x555A9639;

}

int main(int argc, char *argv[]) {
    int             i,
                    x;
    md5_context     md5t;
    unsigned char   md5h[16],
                    guid[33];

    const char      *hex = "0123456789abcdef";


	printf(
		"\ncod4key to pbhash by pierz\n"
		"http://www.indahax.com\n"
		"pierz@indahax.com\n");

 	if(argc < 2){
		printf("usage : ./c4key2guid <key>\n");
		return -1;
	}

	//minus char
	//just need 16 first byte
	for(i=0;i<16;i++)
		argv[1][i] = tolower(argv[1][i]);

	argv[1][16] = '\0';

    cod4_md5_init(&md5t);
    md5_update(&md5t, argv[1], strlen(argv[1]));
    md5_finish(&md5t, md5h);

    for(i = 0, x = 0; i < 16; i++) {
        guid[x++] = hex[md5h[i] >> 4];
        guid[x++] = hex[md5h[i] & 0xf];
    }
    guid[x] = 0;

    printf("\n"
        "GUID:  %s\n"
        "\n",
        guid);

	return(0);
}


