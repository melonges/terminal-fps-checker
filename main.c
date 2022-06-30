#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

time_t lastTime = time(NULL), endTime = lastTime + 10;
int fps = 0, showFps = 0, averageFps[10], averageFpsIndex = 0;

    while (lastTime < endTime) {
        printf("-------fps-------\n");
        printf("\t%d\n", showFps);
        printf("-------fps-------\n");
        time_t currentTime = time(NULL);
        if (currentTime - lastTime >= 1) {
            lastTime = currentTime;
            showFps = fps;
            averageFps[averageFpsIndex] = showFps;
            averageFpsIndex++;
            fps = 0;
        }
        fps++;
        system("clear");
    }
    int sum = 0;
    for (int i = 0; i < averageFpsIndex; ++i) {
        sum += averageFps[i];
    }
    printf("FPS: %d\n", sum / averageFpsIndex);
 return 0;
}
