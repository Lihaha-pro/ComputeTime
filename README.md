# ComputeTime
this program helps compute time

## 程序解析

如果直接使用`clock()`函数计算程序运行时间，计算的是当前线程内在运行时间，所以和实际运行时间不符

针对这一问题，找到了一些解决办法

最简单的计算时间方法：

```cpp
clock_t begTime, endTime;
begTime = clock();
sleep(3);
endTime = clock();
std::cout << "The run time is:" << (double)(endTime - begTime) / CLOCKS_PER_SEC << "s" << std::endl;
return 0;
```

但这样的问题是只能统计线程运行时间，并不是统计实际运行时间，比如调用`sleep()`函数就不记录该时间

该方法可以精确到微秒

如果只需要精确到秒级别，可以这样：

```cpp
clock_t begTime, endTime;
begTime = time(NULL);
sleep(3);
endTime = time(NULL);
std::cout << "The run time is:" << difftime(endTime, begTime) << "s" << std::endl;
return 0;
```

此时输出程序运行时间就是3秒

如果需要更加精确，有待研究哈哈

## 注意事项

想要调用`clock()`，`clock_gettime()`等函数，需要：

```cpp
#include <ctime>
```

想要调用延时函数`sleep()`，需要：

```cpp
#include <unistd.h>
```

对于Linux系统，`sleep()`函数对应的是秒，与Windows系统不同
