#include "main.h"
int main(void)
{
	if (isatty(0))
	{
		printf("interactive");
		loop_for_interactive();
	}
	else
	{
		printf("non-interactive");
		non_interactive();
	}
	return (0);
}
