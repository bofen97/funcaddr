#### 一个命令行小工具

在写操作系统内核用户态系统服务的时候，系统处于一个甚至都没有文件系统和shell（微内核中文件系统作为一个服务在用户态运行）的状态下，这时候内核加载系统服务程序到用户态运行，由于不是直接把系统服务和内核编译在一起（宏内核）的做法，从而没有办法从操作系统中直接debug用户态运行的程序，从外部也无法debug，因为外部运行的qemu-gdb看不到运行在用户态程序符号（甚至这个内核的loader都不加载symbol section），这个时候无法通过qemu-gdb通过符号来下断点debug用户态系统服务，只能通过地址下断点，所以需要找到符号的地址。这个repo期望逐渐实现开发微内核用户态系统服务过程中，为整个过程提供便利 ：）

- 目前只实现给定符号查询所对应虚拟地址的功能（只是如此的话，readelf -s xx.srv | grep funcname 这组命令也可以做到）。


#### 举个🌰
```bash
 ./funcaddr ~/tmpfs.srv tmpfs_creat
 
 -> tmpfs_creat 0x400570

```
