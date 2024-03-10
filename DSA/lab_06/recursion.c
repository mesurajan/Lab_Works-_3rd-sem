/*implement the following
1.HCf
2.lcm
3.factorial
4.fibonacci series upto nth term
5.find nth fibonacci number(term)
6.sum of digits
7.TOH
*/
#include <stdio.h>

// Function to calculate the Highest Common Factor (HCF) of two numbers
int hcf(int a, int b)
{
    if (b == 0)
        return a;
    return hcf(b, a % b);
}

// Function to calculate the Least Common Multiple (LCM) of two numbers
int lcm(int a, int b)
{
    return (a * b) / hcf(a, b);
}

// Function to calculate the factorial of a number
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// Function to generate Fibonacci series up to nth term
void fibonacciSeries(int n)
{
    int i, t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci Series up to %d terms: ", n);
    for (i = 1; i <= n; ++i)
    {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

// Function to find the nth Fibonacci number (term)
int nthFibonacci(int n)
{
    if (n <= 1)
        return n;
    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
}

// Function to calculate the sum of digits of a number
int sumOfDigits(int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int a, b, n, num;
    printf("Enter two numbers for HCF and LCM: ");
    scanf("%d %d", &a, &b);
    printf("HCF of %d and %d is: %d\n", a, b, hcf(a, b));
    printf("LCM of %d and %d is: %d\n", a, b, lcm(a, b));

    printf("Enter a number for factorial: ");
    scanf("%d", &n);
    printf("Factorial of %d is: %d\n", n, factorial(n));

    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);
    fibonacciSeries(n);

    printf("Enter the term to find its Fibonacci number: ");
    scanf("%d", &n);
    printf("The %dth Fibonacci number is: %d\n", n, nthFibonacci(n));

    printf("Enter a number to calculate sum of its digits: ");
    scanf("%d", &num);
    printf("Sum of digits of %d is: %d\n", num, sumOfDigits(num));

    printf("Enter the number of disks for Tower of Hanoi: ");
    scanf("%d", &n);
    printf("Steps to solve Tower of Hanoi problem with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
