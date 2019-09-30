using System;
class Program
{
    public static void Main()
    {
        string s = Console.ReadLine();
        int n = int.Parse(Console.ReadLine());
        int n1, n2;
        n1 = (n - 1) / 5;
        n2 = (n % 5 != 0) ? (n % 5) - 1 : 4;
        Console.WriteLine("{0}{1}", s[n1], s[n2]);
    }
}