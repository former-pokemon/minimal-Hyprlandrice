#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24
#define DEPTH 20
#define SCALE 10

float A = 0, B = 0;

void renderFrame() {
    char buffer[WIDTH * HEIGHT];
    memset(buffer, ' ', sizeof(buffer));

    for (int x = -SCALE; x <= SCALE; x++) {
        for (int y = -SCALE; y <= SCALE; y++) {
            for (int z = -SCALE; z <= SCALE; z++) {
                float tempX = x * cos(A) - z * sin(A);
                float tempZ = x * sin(A) + z * cos(A);
                float tempY = y * cos(B) - tempZ * sin(B);

                int screenX = (int)(WIDTH / 2 + tempX);
                int screenY = (int)(HEIGHT / 2 - tempY);

                if (screenX >= 0 && screenX < WIDTH && screenY >= 0 && screenY < HEIGHT) {
                    buffer[screenY * WIDTH + screenX] = '#';
                }
            }
        }
    }

    printf("\x1b[H");  // Reset cursor to top-left
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        putchar(buffer[i]);
        if ((i + 1) % WIDTH == 0) putchar('\n');
    }
}

int main() {
    printf("\x1b[2J");  // Clear screen

    while (1) {
        renderFrame();
        A += 0.05;
        B += 0.03;
        usleep(30000);  // Delay for smooth animation
    }

    return 0;
}

