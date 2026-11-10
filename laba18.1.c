#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct point
{
    float x;
    float y;
    char name;
};

typedef struct point Point;

void put_point(Point z)
{
    printf("Точка %c (%.1f, %.1f)\n", z.name, z.x, z.y);
}

float dist(Point z, Point w)
{
    return sqrtf(
        (w.x - z.x) * (w.x - z.x) +
        (w.y - z.y) * (w.y - z.y)
    );
}

Point middle(Point z, Point w)
{
    Point m;

    m.x = (z.x + w.x) / 2.0f;
    m.y = (z.y + w.y) / 2.0f;
    m.name = 'M';

    return m;
}

int quarter(Point p)
{
    if (p.x > 0 && p.y > 0)
        return 1;

    if (p.x < 0 && p.y > 0)
        return 2;

    if (p.x < 0 && p.y < 0)
        return 3;

    if (p.x > 0 && p.y < 0)
        return 4;

    return 0;
}

int main()
{
    Point a, b, m;

    printf("Введите имя первой точки: ");
    scanf(" %c", &a.name);

    printf("Введите координаты x и y первой точки: ");
    scanf("%f %f", &a.x, &a.y);

    printf("Введите имя второй точки: ");
    scanf(" %c", &b.name);

    printf("Введите координаты x и y второй точки: ");
    scanf("%f %f", &b.x, &b.y);

    printf("\n");
    put_point(a);
    put_point(b);

    printf("Расстояние между точками = %.2f\n", dist(a, b));

    m = middle(a, b);

    printf("Середина отрезка:\n");
    put_point(m);

    if (quarter(a) == 0)
        printf("Точка %c находится на оси\n", a.name);
    else
        printf("Точка %c находится в %d четверти\n", a.name, quarter(a));

    if (quarter(b) == 0)
        printf("Точка %c находится на оси\n", b.name);
    else
        printf("Точка %c находится в %d четверти\n", b.name, quarter(b));

    return 0;
}