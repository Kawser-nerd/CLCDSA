using System;

class Program
{
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(n % digitSum(n) == 0 ? "Yes" : "No");
    }
    static int digitSum(int n) {
        int sum = 0;
        while(n>0) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
}