#include <time.h>
#include <stdio.h>
#include <stdlib.h>



int main()
{
// animation in terminal

    const char rocket[] =
            "           ^ \n\
          /^\\\n\
          |-|\n\
          | |\n\
          | |\n\
          |F|\n\
          |P|\n\
          |S|\n\
         /| |\\\n\
        / | | \\\n\
       |  | |  |\n\
        `-\"\"\"-`\n\
";

int fps = 0, averageFps[10], averageFpsIndex = 0, inputTime;
    printf("enter the testing time is seconds: \t");
    scanf("%d", &inputTime);
    time_t lastTime = time(NULL), endTime = lastTime + inputTime;
    while (lastTime < endTime) {

        printf("--------FPS--------\n");
        printf("\033[31m");
        printf("\t%d\n", fps);
        printf("\033[0m");
        fputs(rocket,stdout);
        time_t currentTime = time(NULL);
        if (currentTime - lastTime >= 1) {
            lastTime = currentTime;
            averageFps[averageFpsIndex] = fps;
            averageFpsIndex++;
            fps = 0;
        }
        fps++;
        system("clear");
    }
    int sum = 0;
    for (int i = 1; i < averageFpsIndex; ++i) sum += averageFps[i];
    printf("Average FPS: ");
    printf("\033[31m");
    printf("%d\n",sum / (averageFpsIndex - 1));
 return 0;
}



