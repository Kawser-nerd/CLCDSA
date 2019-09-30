using System;

class Program
{
    static void Main(string[] args)
    {
        string[] str = Console.ReadLine().Split() ;
        int h = int.Parse(str[0]);
        int w = int.Parse(str[1]);
        Console.WriteLine((h-1)*w+(w-1)*h);
    }
}