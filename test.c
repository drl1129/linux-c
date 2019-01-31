#include <func.h>
void *threadfunc(void *p)
{
    char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t gtime;
    struct tm *pt;
    time(&gtime);
    pt=gmtime(&gtime);
    printf("child %d-%d-%d",1900 + pt->tm_year, 1 + pt->tm_mon, pt->tm_mday);
    printf("  %s %d:%d:%d\n", wday[pt->tm_wday], pt->tm_hour, pt->tm_min, pt->tm_sec);
    sleep(5);    
    printf("child %d-%d-%d",1900 + pt->tm_year, 1 + pt->tm_mon, pt->tm_mday);
    printf("  %s %d:%d:%d\n", wday[pt->tm_wday], pt->tm_hour, pt->tm_min, pt->tm_sec);
}
int main()
{
    pthread_t pthid;
    pthread_create(&pthid,NULL,threadfunc,NULL);
    sleep(2);
    char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t gtime;
    struct tm *pt;
    time(&gtime);
    pt=gmtime(&gtime);
    printf("main %d-%d-%d",1900 + pt->tm_year, 1 + pt->tm_mon, pt->tm_mday);
    printf("  %s %d:%d:%d\n", wday[pt->tm_wday], pt->tm_hour, pt->tm_min, pt->tm_sec);
    pthread_join(pthid,NULL);
    return 0;
}

