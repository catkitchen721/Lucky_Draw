#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double RandomRangeNumber(double a, double b)
{
    double result = 0.0;
    result = (b - a) * rand() / RAND_MAX + a;
    return result;
}

int main(int argc, char *argv[])
{
    system("title 測試血統");
    srand(time(NULL) + getpid());
    int times = 0;
    double five;
    int fiveget = 0;
    double four;
    int fourget = 0;
    double threedown;
    int i = 0;
    int keep = 0;

    while(1)
    {
        system("cls");
        if(keep == 0)
        {
            fiveget = 0;
            fourget = 0;
            printf("設定機率->(請都輸入0~1之間的小數，總和不能超過1)\n");
            printf("五星\n>");
            scanf("%lf",&five);
            printf("四星\n>");
            scanf("%lf",&four);
            threedown = 1.0 - four - five;
        }
        else if(keep == 1)
        {
            fiveget = 0;
            fourget = 0;
        }
        if(threedown <= 0 || five <= 0 || four <= 0)
        {
            printf("數值範圍有誤\n");
            system("pause");
        }
        else
        {
            printf("五星機率:%f, 四星機率:%f, 其他:%f\n",five, four, threedown);
            printf("抽幾抽?\n>");
            scanf("%d",&times);
            double result = 0.99;
            for(i=0; i<times; i++)
            {
                if((i+1)%10 == 0)
                {
                    result = RandomRangeNumber(0, four+five);
                }
                else
                {
                    result = RandomRangeNumber(0, 1);
                }
                printf("%f",result);
                if(result <= five)
                {
                    printf("★★★★★\n");
                    fiveget++;
                }
                else if(result > five && result <= five + four)
                {
                    printf("★★★★\n");
                    fourget++;
                }
                else
                {
                    printf("★★★以下\n");
                }
            }
            printf("總計:共抽%d抽,五星%d張,四星%d張\n",times, fiveget, fourget);
            printf("保留機率?(好:1, 重設:0)\n");
            scanf("%d",&keep);
        }
    }
    return 0;
}
