#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct P {
	char* name;
	int salaryY;
};
typedef struct P Person;

int main(int argc, char** argv) {
	Person* arr[10];
	Person* top[10];
	char* names[] = {"Jackson", "Ahnna", "Peter", "Pickachu", "John", "Tomas", "Jun", "PoPo", "Limit", "AHHA"};
	int i, size = sizeof(names) / sizeof(char*), max = 0, cnt = 0;
	double mean = 0;
	srand(time(NULL));
	for(i=0; i<size; i++) {
		arr[i] = (Person *)calloc(1, sizeof(Person));
		arr[i] -> name = names[i];
		arr[i] -> salaryY = (rand() % 201 * 10000) + 6000000;
		// if(i == 5) arr[i] -> salaryY = arr[i - 1] -> salaryY;
		printf("name : %s,\t salaryY : %d\n", arr[i] -> name, arr[i] -> salaryY);
		mean += arr[i] -> salaryY;
		max = arr[i] -> salaryY > max ? arr[i] -> salaryY : max;
	}
	mean = mean / size;
	// for(i=0; i<size; i++) {
	// 	max = arr[i].salaryY > max ? arr[i].salaryY : max;
		// if(arr[i].salaryY >= mean) {
		// 	max = arr[i].salaryY > max ? arr[i].salaryY : max;
		// 	top[cnt] = arr[i];
		// 	cnt ++;
		// }
	// }
	for(i=0; i<size; i++) {
		if(arr[i] -> salaryY >= max) {
			top[cnt] = arr[i];
			cnt ++;
		}
	}
	printf("mean val : %.2f\n", mean);

	printf("best salary man!\n");
	for(i=0; i<cnt; i++) printf("name : %s,\t salaryY : %d\n", top[i] -> name, top[i] -> salaryY);
	return 0;
}