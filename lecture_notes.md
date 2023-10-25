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

## Lecture 4

### Pointers
When initiating a variable, `char a = 10`, a spot inside the memory is saved for the varaible `a` and value `10` is stored inside. A pointer is **a variable that stores an address**.

```C
char a = 10;
char* p;
p  = &a;
```

### Pointers in arrays
When passing arrays, we are already passing the address (of the first element). No need to use `&` when we want to pass an address.

```C
printf("%c", s[0]); => 't'
printf("%c", *s); => 't'
printf("%p", &s[0]); => 1101

```

### Swap function
When we want to change the variable, we pass the address to the function, the function will access the value with `*var_name` and change it. **Notice that `int *n1` input is not accessing value but stating that it is an address.**
```C
void swap(int *n1, int *n2) {
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

int main() {
    ...
    swap(&n1, &n2);
}
```
