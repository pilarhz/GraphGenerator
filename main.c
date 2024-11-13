#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// y   x
g[50][100];

void set_graph() {
	for (int y = 0; y <= 49; y++) {
		for (int x = 0; x <= 99; x++) {
			if (x == 49 && y == 24) {
				g[y][x] = '+';
			}
			else if (x == 49) {
				g[y][x] = '|';
			}
			else if (y == 24) {
				g[y][x] = '-';
			}
			else {
				g[y][x] = ' ';
			}
		}
	}
};

void show_graph() {
	printf("\n");
	for (int y = 0; y <= 49; y++) {
		for (int x = 0; x <= 99; x++) {
			printf("%c", g[y][x]);
		}
		printf("\n");
	}
};

void linear_function() {
	// y = ax + b
	int a = 0, b = 0;
	int y = 0;
	char znak = '#';
	printf("y = ax + b\n");
	printf("a: ");
	scanf_s("%d", &a);
	printf("b: ");
	scanf_s("%d", &b);
	system("cls");

	if (b >= 0) { printf("y = %dx + %d", a, b); }
	else if (b < 0) { printf("y = %dx + (%d)", a, b); }

	if (a > 0) { znak = '/'; }
	else if (a < 0) { znak = '\\'; }
	int x = -49;
	for (int i = 0; i <= 99; i++) {
		y = a * x + b;
		if (y >= 0 && y <= 25) {
			y = 24 - y;
			g[y][i] = znak;
		}
		else if (y < 0 && y >= -25) {
			y = 24 + (-1) * y;
			g[y][i] = znak;
		}
		x++;
	}
	show_graph();
};

int main() {
	set_graph();
	int p = 0;
	while (1) {
		printf("Choose which function you want to make\n");
		printf("1 - Linear\n");
		printf("2 - Exit\n= ");
		scanf_s("%d", &p);
		if (p == 1) {
			linear_function();
		}
		else if (p == 2) {
			return -1;
		}
	}
}