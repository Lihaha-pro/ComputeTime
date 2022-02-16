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

但这样的问题是只能统计线程运行时间，并不是统计实际运行时间，比如调用`sleep()`函数就不会记录该该函数运行的时间

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

## GLOG方法

通过使用glog库，可以实现程序状态的输出，其中就包括输出系统时间，因此可以通过glog命令进行耗时统计

具体方法为使用如下命令：

```cpp
LOG(INFO) << std::endl;
```

其中`LOG(INFO)`可以打印系统时间到终端

然后配合使用`nohup`重定向输出到`.txt`文件，再利用程序对`.txt`进行数据处理

### nohup相关介绍

这篇博客写的很棒：[Linux后台运行命令nohup实现屏幕输出记录到日志文件](https://blog.csdn.net/sitebus/article/details/100554789)

**功能实现**

实际使用时，采用如下格式：

```bash
nohup [command] > 1.log &
```

这样就可以实现后台运行`command`命令

此时可以通过该指令查看当前终端产生的进程的进程**PID**号：

```bash
jobs -l
```

得到PID号后，可杀死该后台进程：

```bash
kill -9 PID
```

此时也可发现`1.log`中输出内容不再更新

此时可以使用如下指令查看进程是否被杀死：

```bash
jobs
```

另外也可以通过该指令查看所有运行中的进程：

```bash
ps ux
```

