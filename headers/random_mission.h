#ifndef RANDOM_MISSION_H_INCLUDED
#define RANDOM_MISSION_H_INCLUDED
void random_mission(int b[],unsigned int num);
void random_mission(int b[],unsigned int num)
{
    int a[num],i,j,temp=0;
    srand((unsigned)time(0));
    while(1)
    {
        int check=1;
        for(i=0;i<num;i++)
            a[i]=rand()%1000;
        for(i=0;i<num;i++)///自检重复
            for(j=i+1;j<num;j++)
                if(a[i]==a[j])
                    check=0;
        if(check==1)///不重复判定
            break;
    }
    for(i=0;i<num;i++)
        b[i]=a[i];
    for(i=0;i<num;i++)
        for(j=0;j<num-1;j++)
            if(b[j]>b[j+1])
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
    for(i=0;i<num;i++)///将随机顺序传给数组b
        for(j=0;j<num;j++)
            if(b[i]==a[j])
                b[i]=j;
}
#endif // RANDOM_MISSION_H_INCLUDED
