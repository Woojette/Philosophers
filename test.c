#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

// Define ANSI escape sequences for colors and styles
#define BOLD_CYAN "\033[1;36m"
#define RESET "\033[0m"

int main()
{
    struct timeval start, end;

	// start.tv_sec;
	// start.tv_usec;
    gettimeofday(&start, NULL); // Get the current time before sleeping
    usleep(1000000);  // Expected sleep: 500 milliseconds (0.5 seconds)
    gettimeofday(&end, NULL);  // Get the time after sleeping

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;

    double elapsedMilliseconds = (seconds * 1000.0) + (microseconds / 1000.0);

    printf("Expected sleep duration: "BOLD_CYAN"\t500 milliseconds\n"RESET);
    printf("Actual sleep duration: "BOLD_CYAN"\t\t%.2f milliseconds\n\n"RESET, elapsedMilliseconds);

	printf("sec:%ld\n", start.tv_sec * 1000 + start.tv_usec / 1000);
	printf("sec:%ld\n", end.tv_sec * 1000 + end.tv_usec / 1000);

	printf("sec:%ld\n", (end.tv_sec  * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));

	// printf("sec:%ld\n", end.tv_sec);

	// printf("sec:%ld\n", end.tv_sec - start.tv_sec);


	// printf("micro:%ld\n", start.tv_usec / 1000);

	// printf("sec:%ld\n", end.tv_sec);

	// printf("sec:%ld\n", end.tv_sec - start.tv_sec);
    return 0;
}
//1 sec = 1000 millisec = 1 000 000 microsec

// 1 millisec  = 1000 microsec