# Cool

This repo contains my study resources from CS143.

Cool is a tiny compiler.

Enjoy it and have fun.


Notes
-----


Lex
----
----

Lex是一个工具，它支持使用正则表达式来描述各个词法单元的模式，通过Lex可以很简单的给出一个词法分析器的规约。

![lex原理](./images/lex.png)

一个Lex程序具有下列的形式

```
声明部分
%%
转换规则
%%
辅助函数
```

* 声明部分
声明部分包括常量和明示变量(manifest constant),如果Lex跟Yacc一起使用的话，那么明示变量通常会在Yacc程序中定义，并在Lex程序中不加定义就使用它们。

* 转换规则
转换规则具有下列的格式: `模式 {动作}`
每一个模式是一个正则表达式，它可以使用声明部分中给出的正则定义，动作部分是代码片段，会被直接拷贝到`lex.yy.cc`里面去的。

* 辅助函数
可有可无。


