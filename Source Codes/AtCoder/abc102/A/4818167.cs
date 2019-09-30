using System;
using System.Linq;
class Program
{
    static void Main()
    {
        //int[] input = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        int input=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        Console.WriteLine(input%2==0?input:input*2);
        Console.ReadLine();
    }
}