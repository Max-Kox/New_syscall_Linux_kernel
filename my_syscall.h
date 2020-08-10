enum my_syscall_api_ver {
	MY_SYS_API_VER_1 = 1,
	MY_SYS_API_VER_2 = 2,
};

typedef struct {
	size_t len;
	char str[0];
} my_string_t;

// input data structure - API version 1:
struct my_syscall_in_data {
	my_string_t *name;
	unsigned int val;
};

// Input data structure - API version 2:
struct my_syscall_in_data2 {
	my_string_t *name;
	unsigned int val;
	unsigned int val2;
};

// Output data structure - API version 1:
struct my_syscall_out_data {
	unsigned int data;
};

// Output data structure - API version 2:
struct my_syscall_out_data2 {
	unsigned int data;
	unsigned long data2;
};

