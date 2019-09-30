using System;
using System.Linq;
class Program
{
    static void Main()
    {
        //int[] input = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        int a=int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        Console.WriteLine(a%b==0?0:b- a % b);
        Console.ReadLine();
    }
}