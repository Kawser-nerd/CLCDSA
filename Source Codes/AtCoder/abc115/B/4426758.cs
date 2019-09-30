using System;

class Program
{
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[] p = new int[n];
        for (int i = 0; i < n; i ++) p[i] = int.Parse(Console.ReadLine());
        Array.Sort(p);
        int sum = 0;
        sum += p[n-1]/2;
        for (int i = 0; i < n-1; i ++) sum += p[i];
        Console.WriteLine(sum);
    }
}