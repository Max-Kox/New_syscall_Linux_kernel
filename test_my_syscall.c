#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_syscall.h"

#define __NR_my_syscall		440
#define SYS_my_syscall		__NR_my_syscall


int main(void)
{
	int ret = 0;
	my_string_t *in_name;
	struct my_syscall_in_data *in_data;
	struct my_syscall_out_data *out_data;

	in_data = malloc(sizeof(struct my_syscall_in_data));
	in_name = malloc(100);
	snprintf(&in_name->str[0], 100, "Hello\n");
	in_name->len = 6;
	in_data->name = in_name;
	in_data->val = 15;

	out_data = malloc(sizeof(struct my_syscall_out_data));

	ret = syscall(SYS_my_syscall, MY_SYS_API_VER_1, in_data, out_data);
	printf("syscall return: %d\n", out_data->data);

	return 0;
	
}
