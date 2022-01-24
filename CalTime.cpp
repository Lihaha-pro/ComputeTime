#include <iostream>
#include <ctime>
#include <unistd.h>
/**
 * @brief 计算两个时间间隔
 * 
 * @param m1 
 * @param s1 
 * @param m2 
 * @param s2 
 * @return int 
 */
void CalculateTime(int m1, int s1, int m2, int s2)
{
    std::cout << "time1 = " << m1 << ":" << s1 << std::endl;
    std::cout << "time2 = " << m2 << ":" << s2 << std::endl;
    int time;
    time = (m2 - m1) * 60 + s2 - s1;
    std::cout << "delta time is " << time << "s" << std::endl;
}
int main()
{
    clock_t begTime, endTime;
    // begTime = clock();
    begTime = time(NULL);
    // std::cout << "please enter two time" << std::endl;
    // int m1, m2, s1, s2;
    // std::cin >> m1 >> s1 >> m2 >> s2;
    // CalculateTime(m1, s1, m2, s2);
    sleep(10);
    // endTime = clock();
    endTime = time(NULL);
    std::cout << "The run time is:" << difftime(endTime, begTime) << "s" << std::endl;
    // std::cout << "The run time is:" << (double)(endTime - begTime) / CLOCKS_PER_SEC << "s" << std::endl;
    // struct timespec ts;
    // clock_gettime(CLOCK_MONOTONIC, &ts);
    // std::cout << "The run time is:" << ts.tv_sec << "s" << std::endl;
    return 0;
}
