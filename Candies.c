#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

struct stu{
    int id;
    int rating;
};

int comp( const void*p1, const void*p2){
    return ((struct stu*)p1)->rating - ((struct stu*)p2)->rating;
}

struct stu student[MAXN];
int candies[MAXN];
int ratings[MAXN];

int main(int argc, char *argv[])
{
    int N;
    int i,j;
    int candy;
    int id;
    long long sumcandies = 0;

    scanf("%d",&N);
    for(i = 0; i < N; i++){
        scanf("%d",&student[i].rating);
        student[i].id = i;
        ratings[i] = student[i].rating;
    }

    qsort(student,N,sizeof(struct stu),comp);
    
    for(i = 0; i < N; i++){
        id = student[i].id;
        candy = 1;

        if(id > 0){
            if(candies[id-1] != 0 && ratings[id] > ratings[id-1]){
                candy = candies[id-1] + 1;
            }
        }

        if(id < N-1){
            if(candies[id+1] != 0 && ratings[id] > ratings[id+1] &&
               candy <= candies[id+1]){
                candy = candies[id+1] + 1;
            }
        }

        sumcandies += candy;
        candies[id] = candy;
    }

    printf("%lld\n",sumcandies);
    return 0;
}

 
