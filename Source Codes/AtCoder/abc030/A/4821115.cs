using System;
using System.Linq;
class Program
{
    static void Main()
    {
        double[] input = Console.ReadLine().Split().Select(i => double.Parse(i)).ToArray();
        //int a=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        Console.WriteLine(input[0]/input[1]<input[2]/input[3]?"TAKAHASHI": input[0] / input[1] > input[2] / input[3]?"AOKI":"DRAW");
        Console.ReadLine();
    }
}