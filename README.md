# algebra
王博文第一次作业
## 作业内容 
* [作业结果呈现1](https://icnplnuf1spz.feishu.cn/wiki/FS1mw9RhhioJuwkyZXoctxmWn8L)
* [作业结果呈现2](https://icnplnuf1spz.feishu.cn/wiki/RgFRwRuaJifGi0kL688cDZi0n5f)
好像截多了，除了rank都是有的。
## 实现思路
加减部分比较简单，就是判断矩阵类型相同后直接运用符号做2次嵌套循环。
乘的思路主要也是嵌套循环，用两次循环进行定位，然后再设一个变量`k`来做到对应数字相乘后结果相加即可。
数乘也比较简单，思路同加减。
转置的话是另外设一个`c`，使得`c.data[i][j]`和`a.data[j][i]`相等即可。
求行列式的话主要是利用了嵌套函数，用代数余子式的办法递归成单个数字矩阵，当然它的行列式就是本身了。
求逆也是差不多，先嵌套循环求出余子式的矩阵形式，然后利用求行列式的函数求出余子式和整体的行列式，就可以一项一项求出结果了。
迹也比较简单，`a.data[i][i]`求和即可。
