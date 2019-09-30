using System;
using System.Linq;
class Program
{
    static void Main()
    {
        //int[] input = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        int a=int.Parse(Console.ReadLine());
        Console.WriteLine(a % 2 == 0?a/2:a/2+1);
        Console.ReadLine();
    }
}