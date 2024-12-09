#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define M_PI 3.14159265358979323846

typedef struct
{
    double x;
    double y;
    double z;
} points;

typedef struct
{
    char type[15];
    int totalver, out;
    points vertices[9];
} shapes;

shapes shape[1001];

void scancube(int idx)
{
    strcpy(shape[idx].type, "CUBE");
    shape[idx].totalver = 8;
    for (int i = 0; i < 8; i++)
    {
        scanf("%lf %lf %lf", &shape[idx].vertices[i].x, &shape[idx].vertices[i].y, &shape[idx].vertices[i].z);
    }
}

void scanprism(int idx)
{
    strcpy(shape[idx].type, "PRISM");
    shape[idx].totalver = 6;
    for (int i = 0; i < 6; i++)
    {
        scanf("%lf %lf %lf", &shape[idx].vertices[i].x, &shape[idx].vertices[i].y, &shape[idx].vertices[i].z);
    }
}

void scanpyr(int idx)
{
    strcpy(shape[idx].type, "PYRAMID");
    shape[idx].totalver = 5;
    for (int i = 0; i < 5; i++)
    {
        scanf("%lf %lf %lf", &shape[idx].vertices[i].x, &shape[idx].vertices[i].y, &shape[idx].vertices[i].z);
    }
}

int main()
{
    
    strcpy(shape[100].type, "Cam");
    shape[100].totalver = 4;
    for (int i = 0; i < 4; i++)
    {
        scanf("%lf %lf %lf", &shape[100].vertices[i].x, &shape[100].vertices[i].y, &shape[100].vertices[i].z);
    }

    int M;
    scanf("%d", &M);

    int idx = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%s", shape[idx].type);
        if (strcmp(shape[idx].type, "CUBE") == 0)
        {
            scancube(idx);
        }
        else if (strcmp(shape[idx].type, "PRISM") == 0)
        {
            scanprism(idx);
        }
        else if (strcmp(shape[idx].type, "PYRAMID") == 0)
        {
            scanpyr(idx);
        }
        idx++;
    }

    int T;
    scanf("%d", &T);

    char cmd[100];
    for (int i = 0; i < T; i++)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "ROTATE") == 0)
        {
            int deg, num;
            char bythe;
            double rad;

            scanf("%d %c %d", &num, &bythe, &deg);
            rad = (double)(deg * M_PI) / 180;

            double xAxis[3][3] = {{1, 0, 0}, {0, cos(rad), -sin(rad)}, {0, sin(rad), cos(rad)}};
            double yAxis[3][3] = {{cos(rad), 0, sin(rad)}, {0, 1, 0}, {-sin(rad), 0, cos(rad)}};
            double zAxis[3][3] = {{cos(rad), -sin(rad), 0}, {sin(rad), cos(rad), 0}, {0, 0, 1}};

            for (int i = 0; i < shape[num - 1].totalver; i++)
            {
                if (bythe == 'X')
                {
                    double newX = (xAxis[0][0] * shape[num - 1].vertices[i].x) + (xAxis[0][1] * shape[num - 1].vertices[i].y) + (xAxis[0][2] * shape[num - 1].vertices[i].z);
                    double newY = (xAxis[1][0] * shape[num - 1].vertices[i].x) + (xAxis[1][1] * shape[num - 1].vertices[i].y) + (xAxis[1][2] * shape[num - 1].vertices[i].z);
                    double newZ = (xAxis[2][0] * shape[num - 1].vertices[i].x) + (xAxis[2][1] * shape[num - 1].vertices[i].y) + (xAxis[2][2] * shape[num - 1].vertices[i].z);

                    shape[num - 1].vertices[i].x = newX;
                    shape[num - 1].vertices[i].y = newY;
                    shape[num - 1].vertices[i].z = newZ;
                }
                else if (bythe == 'Y')
                {
                    double newX = (yAxis[0][0] * shape[num - 1].vertices[i].x) + (yAxis[0][1] * shape[num - 1].vertices[i].y) + (yAxis[0][2] * shape[num - 1].vertices[i].z);
                    double newY = (yAxis[1][0] * shape[num - 1].vertices[i].x) + (yAxis[1][1] * shape[num - 1].vertices[i].y) + (yAxis[1][2] * shape[num - 1].vertices[i].z);
                    double newZ = (yAxis[2][0] * shape[num - 1].vertices[i].x) + (yAxis[2][1] * shape[num - 1].vertices[i].y) + (yAxis[2][2] * shape[num - 1].vertices[i].z);

                    shape[num - 1].vertices[i].x = newX;
                    shape[num - 1].vertices[i].y = newY;
                    shape[num - 1].vertices[i].z = newZ;
                }
                else if (bythe == 'Z')
                {
                    double newX = (zAxis[0][0] * shape[num - 1].vertices[i].x) + (zAxis[0][1] * shape[num - 1].vertices[i].y) + (zAxis[0][2] * shape[num - 1].vertices[i].z);
                    double newY = (zAxis[1][0] * shape[num - 1].vertices[i].x) + (zAxis[1][1] * shape[num - 1].vertices[i].y) + (zAxis[1][2] * shape[num - 1].vertices[i].z);
                    double newZ = (zAxis[2][0] * shape[num - 1].vertices[i].x) + (zAxis[2][1] * shape[num - 1].vertices[i].y) + (zAxis[2][2] * shape[num - 1].vertices[i].z);

                    shape[num - 1].vertices[i].x = newX;
                    shape[num - 1].vertices[i].y = newY;
                    shape[num - 1].vertices[i].z = newZ;
                }
            }
        }
        else if (strcmp(cmd, "TRANSLATE") == 0)
        {
            int num;
            double a, b, c;
            scanf("%d %lf %lf %lf", &num, &a, &b, &c);
            for (int i = 0; i < shape[num - 1].totalver; i++)
            {
                shape[num - 1].vertices[i].x += a;
                shape[num - 1].vertices[i].y += b;
                shape[num - 1].vertices[i].z += c;
            }
        }
        else if (strcmp(cmd, "REFLECT") == 0)
        {
            int num;
            char bythe;

            scanf("%d %c", &num, &bythe);

            double byX[3][3] = {{1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
            double byY[3][3] = {{-1, 0, 0}, {0, 1, 0}, {0, 0, -1}};
            double byZ[3][3] = {{-1, 0, 0}, {0, -1, 0}, {0, 0, 1}};

            for (int i = 0; i < shape[num - 1].totalver; i++)
            {
                if (bythe == 'X')
                {
                    shape[num - 1].vertices[i].x = byX[0][0] * shape[num - 1].vertices[i].x + byX[0][1] * shape[num - 1].vertices[i].y + byX[0][2] * shape[num - 1].vertices[i].z;
                    shape[num - 1].vertices[i].y = byX[1][0] * shape[num - 1].vertices[i].x + byX[1][1] * shape[num - 1].vertices[i].y + byX[1][2] * shape[num - 1].vertices[i].z;
                    shape[num - 1].vertices[i].z = byX[2][0] * shape[num - 1].vertices[i].x + byX[2][1] * shape[num - 1].vertices[i].y + byX[2][2] * shape[num - 1].vertices[i].z;
                }
                else if (bythe == 'Y')
                {
                    shape[num - 1].vertices[i].x = byY[0][0] * shape[num - 1].vertices[i].x + byY[0][1] * shape[num - 1].vertices[i].y + byY[0][2] * shape[num - 1].vertices[i].z;
                    shape[num - 1].vertices[i].y = byY[1][0] * shape[num - 1].vertices[i].x + byY[1][1] * shape[num - 1].vertices[i].y + byY[1][2] * shape[num - 1].vertices[i].z;
                    shape[num - 1].vertices[i].z = byY[2][0] * shape[num - 1].vertices[i].x + byY[2][1] * shape[num - 1].vertices[i].y + byY[2][2] * shape[num - 1].vertices[i].z;
                }
                else if (bythe == 'Z')
                {
                    shape[num - 1].vertices[i].x = byZ[0][0] * shape[num - 1].vertices[i].x + byZ[0][1] * shape[num - 1].vertices[i].y + byZ[0][2] * shape[num - 1].vertices[i].z;
                    shape[num - 1].vertices[i].y = byZ[1][0] * shape[num - 1].vertices[i].x + byZ[1][1] * shape[num - 1].vertices[i].y + byZ[1][2] * shape[num - 1].vertices[i].z;
                    shape[num - 1].vertices[i].z = byZ[2][0] * shape[num - 1].vertices[i].x + byZ[2][1] * shape[num - 1].vertices[i].y + byZ[2][2] * shape[num - 1].vertices[i].z;
                }
            }
        }
        else if (strcmp(cmd, "SCALE") == 0)
        {
            int num;
            double a, b, c;

            scanf("%d %lf %lf %lf", &num, &a, &b, &c);

            int ver = shape[num - 1].totalver;
            for (int i = 0; i < ver; i++)
            {
                shape[num - 1].vertices[i].x *= a;
                shape[num - 1].vertices[i].y *= b;
                shape[num - 1].vertices[i].z *= c;
            }
        }
    }

    double xmin = 1e9, xmax = -1e9, ymin = 1e9, ymax = -1e9, zmin = 1e9, zmax = -1e9;

    for (int i = 0; i < 4; i++)
    {
        if (xmax < shape[100].vertices[i].x)
        {
            xmax = shape[100].vertices[i].x;
        }
        if (ymax < shape[100].vertices[i].y)
        {
            ymax = shape[100].vertices[i].y;
        }
        if (zmax < shape[100].vertices[i].z)
        {
            zmax = shape[100].vertices[i].z;
        }
    }

    xmin = xmax;
    ymin = ymax;
    zmin = zmax;

    for (int i = 0; i < 4; i++)
    {

        if (xmin > shape[100].vertices[i].x)
        {
            xmin = shape[100].vertices[i].x;
        }
        if (ymin > shape[100].vertices[i].y)
        {
            ymin = shape[100].vertices[i].y;
        }
        if (zmin > shape[100].vertices[i].z)
        {
            zmin = shape[100].vertices[i].z;
        }
    }

    for (int i = 0; i < M; i++)
    {
        shape[i].out = 0;
        for (int j = 0; j < shape[i].totalver; j++)
        {
            double x = shape[i].vertices[j].x;
            double y = shape[i].vertices[j].y;
            double z = shape[i].vertices[j].z;

            if (x < xmin || y <= ymin || y >= ymax || z <= zmin || z >= zmax)
            {
                shape[i].out++;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        if (shape[i].out == shape[i].totalver)
        {
            printf("Shape %d: %s, is in your imagination only!\n", i + 1, shape[i].type);
        }
        else if (shape[i].out > 0 && shape[i].out < shape[i].totalver)
        {
            printf("Shape %d: %s, is... not looking complete?\n", i + 1, shape[i].type);
        }
        else
        {
            printf("Shape %d: %s, can be seen clearly in all its beauty!\n", i + 1, shape[i].type);
        }
    }
}
