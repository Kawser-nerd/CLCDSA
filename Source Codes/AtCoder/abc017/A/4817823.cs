using System;
using System.Linq;
class Program
{
    static void Main()
    {
        //int[] input = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        //int a=int.Parse(Console.ReadLine());
        //int b = int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        //string b = Console.ReadLine();
        int total = 0;
        for(int a = 0; a < 3; a++)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            total += input[1] * input[0] / 10;
        }
        Console.WriteLine(total);
        //Console.WriteLine(input[0]%input[1]==0?"YES":"NO");
        Console.ReadLine();
    }
}