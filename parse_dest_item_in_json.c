#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void parse_dest_item(const char *srccmd, const char*destcmd, char cmd[])
{
	if (NULL == srccmd || NULL == destcmd)
	{
		printf("srccmd or destcmd is NULL so return\r\n");
		return;
	}

	char *pstr = strstr((char*)srccmd, destcmd);
	if (NULL == pstr)
	{
		return;
	}

	pstr = pstr + strlen(destcmd);
	char *pbegin = pstr;
	char *pcmd = cmd;
	while (*pbegin++ != '\0')
	{
		if (*pbegin == ',' || *pbegin == '}')
		{
			break;
		}
		if (0 != isspace(*pbegin))
		{
			continue;
		}
		if (0 == isalpha(*pbegin))
		{
			if (':' == *pbegin || '"' == *pbegin)
				continue;
		}
		*pcmd++ = *pbegin;
	}
}
int main()
{
	char cmd[128] = { '\0' };
	const char*parsecmd = "{\"cmd\":\" lora \",\"test\":\" rx_start\",\"para\":{\"rf\": 512 }}";

	memset(cmd, '\0', sizeof(cmd));
	parse_dest_item(parsecmd, "cmd", cmd);
	printf("cmd=%s\r\n", cmd);

	memset(cmd,'\0', sizeof(cmd));
	parse_dest_item(parsecmd, "test", cmd);
	printf("cmd=%s\r\n", cmd);

	memset(cmd, '\0', sizeof(cmd));
	parse_dest_item(parsecmd, "rf", cmd);
	printf("cmd=%s\r\n", cmd);
	return 0;
}