#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define DEV_NAME	"/dev/hubuyu"

int main()
{	
	int fd ;
	int err ;
	char led_value=1;
	char led_rd = 0 ;
	int i = 0 ;
	fd = open(DEV_NAME,O_RDWR);
	if(fd<0)
	{
		printf("Open %s failed \n" ,DEV_NAME );	
		return -1 ;
	};

	do{
		err = write(fd , &led_value , sizeof(led_value));
		if(err<0){
			printf("Write data to kernel failed\n");
		return -1 ;
		}	
		err = read(fd , &led_rd ,sizeof(led_rd));
		if(err<0){
			printf("Read data from kernel failed\n");
			return -1 ;
		}
		printf("LED is %s(%d)\n" , (led_rd==1)?"ON":"OFF", led_rd);
		sleep(1);
		led_value = ~led_value;
	}while(i++<10);
/*	
	err = read(fd , data ,sizeof(data));
	printf("read length is %d \n", sizeof(data));
	if(err<0){
		printf("Read data from kernel failed\n");
		return -1 ;
	}
	printf("Read data-%s \n",data);
*/
	close(fd);
}
