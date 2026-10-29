# C++ Learning Notes

C++ 学习练习仓库，包含基础语法练习、教材章节示例，以及逐步迭代的银行账户系统。

## 目录结构

```text
CPP/
├── learning/     # 基础语法：输入输出、引用、重载、命名空间等
├── book/         # 教材章节示例（Chapter 3–16）
└── OOP/          # 银行系统项目，从 Ver01 迭代到 Ver11
```

### `learning/`

入门练习，覆盖加法、函数重载、默认参数、引用、内联函数、命名空间等。

### `book/`

按章节组织的示例与作业：

| 章节 | 主要内容 |
|------|----------|
| Chapter 3–4 | 类与对象、封装 |
| Chapter 5–6 | 拷贝构造、对象关系 |
| Chapter 7–8 | 继承、虚函数 |
| Chapter 9 | 多重继承 |
| Chapter 10–11 | 运算符重载、仿函数 |
| Chapter 12 | 字符串类 |
| Chapter 13–14 | 函数模板、类模板 |
| Chapter 15 | 异常处理 |
| Chapter 16 | 类型转换（`static_cast` / `dynamic_cast` 等） |

### `OOP/`

银行账户系统的演进版本（`BankingSystemVer01` → `Ver11`），逐步加入继承、虚函数、数组封装、自定义 `String`、异常处理等。

## 编译运行

环境：macOS + `clang++`。

单文件示例：

```bash
clang++ -g example.cpp -o example
./example
```

多文件项目（以 `OOP/BankingSystemVer11` 为例）：

```bash
cd OOP/BankingSystemVer11
clang++ -g *.cpp -o BankingSystemMain
./BankingSystemMain
```

VS Code / Cursor 中可直接用已有的 C/C++ build 任务编译当前打开的 `.cpp` 文件。

## 说明

仓库只跟踪源代码（`.cpp` / `.h`）和必要的编辑器配置。编译生成的可执行文件、`.dSYM` 调试符号和 `.DS_Store` 不会提交。
