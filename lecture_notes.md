# Lecture Notes
\* Will be taking memos of stuff I didn't know

## Lecture 1
To compile and run a C code,
```
gcc test.c -o test.out
./test.out
```

When trying to print out an integer, need to use %d
```
printf("Numbers: %d and %d", a, b);
```

## Lecture 2
### Switch expressions
An if-like expression that checks for variable value
```
switch(x) {
    case 0: printf("x is 0\n"); break;
    case 1: printf("x is 1\n"); break;
    default: printf("x is not 1 nor 0");
}
```
### Function
To define functions, need to declare the return type. If no return, use `void`
```
int add(int a, int b) {
    int x;
    x = a + b;
    return x
}
```
**Prototype Declaration**

Before defining a function, we can define the interface of the function to compiler
```
int add(int, int);

int add(int a, int b) {
    function...
}
```
### Cast
Forcefully trying to change type

\* ex.double to int
```
double w = 3.9;
int x = (int) w;
```
### math.h
Include `<math.h>` library for mathematical functions. Have to compile with `-Wall` and `-lm`
```
gcc -Wall -o kadai kadai.c -lm
```
Useful functions include `pow`, `sqrt`, `cos`, `exp`, `log` and `fabs`.


## Lecture 3

### 再帰呼び出し (Recursion)
No notes. No new stuff.
