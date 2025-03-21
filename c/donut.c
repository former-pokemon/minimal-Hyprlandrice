#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

int k;
float A, B, C;

void renderFrame() {
    float z[1760];
    char b[1760];
    printf("\x1b[H"); // Clear screen and reset cursor position
    
    memset(b, 32, 1760); // Fill buffer with spaces
    memset(z, 0, 7040);  // Reset depth buffer

    for (float j = 0; j < 6.28; j += 0.07) {
        for (float i = 0; i < 6.28; i += 0.02) {
            float c = sin(i);
            float d = cos(j);
            float e = sin(A);
            float f = sin(j);
            float g = cos(A);
            float h = d + 2;
            float D = 1 / (c * h * e + f * g + 5);
            float l = cos(i);
            float m = cos(B);
            float n = sin(B);
            float t = c * h * g - f * e;

            int x = 40 + 30 * D * (l * h * m - t * n);
            int y = 12 + 15 * D * (l * h * n + t * m);
            int o = x + 80 * y;

            int N = (int)(8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n));

            if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                z[o] = D;
                b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
            }
        }
    }

    for (k = 0; k < 1760; k++) {
        putchar(k % 80 ? b[k] : 10); // Print each character or a newline
    }
}

int main() {
    printf("\x1b[2J"); // Clear screen
    for (;;) {
        renderFrame();
        A += 0.04;
        B += 0.08;
        usleep(30000); // Add delay for smooth animation
    }
    return 0;
}

