#include <stdio.h>
#include <time.h>

int main(void) {
    time_t start_time, end_time;
    double duration;
    int minutes, seconds;
    
    
    printf("This program will time how long you can hold your breath.\n");
    printf("Take a deep breath, then press the 'Enter' key.\n");
    printf("When you absolutely have to exhale, press the enter key again.\n");
    printf("The duration will be displayed in minutes and seconds.\n\n");
    
    printf("Press Enter to start timing...");
    
    
    getchar();
    start_time = time(NULL);
    
    printf("Holding... Press Enter when you need to breathe!\n");
    
    
    getchar();
    end_time = time(NULL);
    

    duration = difftime(end_time, start_time);
    minutes = (int)duration / 60;
    seconds = (int)duration % 60;
    
   
    printf("\nYou held your breath for: %d minute(s) and %d second(s)\n", minutes, seconds);
    
    return 0;
}