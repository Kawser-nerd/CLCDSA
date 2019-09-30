using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        List<int> list = new List<int>();
        for (int i = 1; i < n; i ++) {
            int a = i;
            int b = n-i;
            list.Add(digitSum(a)+digitSum(b));
        }
        Console.WriteLine(list.Min());
    }
    static int digitSum(int x) {
        if(x < 10) return x;
        else return digitSum(x/10) + x%10;
    }
}