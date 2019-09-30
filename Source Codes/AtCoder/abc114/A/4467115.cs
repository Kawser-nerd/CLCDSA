using System;

class Program
{
    public static void Main(string[] args) {
        int x = int.Parse(Console.ReadLine());
        if (x == 7 || x == 5 || x == 3) Console.WriteLine("YES");
        else Console.WriteLine("NO");
    }
}