using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int input =int.Parse(Console.ReadLine());
        int max = 0;
        for(int a = 0; a < input; a++)
        {
            if (max < (input - a) * (a)) max = (input - a) * (a);
        }
        Console.WriteLine(max);
        Console.ReadLine();
    }
}