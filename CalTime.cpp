#include <iostream>

int main()
{
    std::cout << "please enter two time" << std::endl;
    int m1, m2, s1, s2;
    std::cin >> m1 >> s1 >> m2 >> s2;
    std::cout << "time1 = " << m1 << ":" << s1 << std::endl;
    std::cout << "time2 = " << m2 << ":" << s2 << std::endl;
    int time;
    time = (m2 - m1) * 60 + s2 - s1;
    std::cout << "delta time is " << time << std::endl;
    return 0;
}