# Gomoku

## 使用到的技术要点

- 宏定义避免重复编译
- 类的继承
- 异常处理
- 运算符重载
- STL中map

- 函数重载
- 拷贝构造函数

## 编译

```shell
# 直接 g++
g++ src/*.h src/*.cpp -o debug/gomoku.out
./gomoku.out

# 使用 也可以 cmake
mkdir build
cd build
cmake ..
make
./gomoku
```
