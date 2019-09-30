using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int[] input = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        //int input=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        Console.WriteLine(input[1]-input[0]==input[2]-input[1]?"YES":"NO");
        Console.ReadLine();
    }
}