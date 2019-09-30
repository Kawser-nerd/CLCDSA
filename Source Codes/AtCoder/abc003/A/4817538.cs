using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int avg = 0;
        int input = int.Parse(Console.ReadLine());
        for (int a = 0;a < input; a++)
        {
            avg += (a+1)*10000;
        }
        avg=avg /input;

        Console.WriteLine((int)avg);
        Console.ReadLine();
    }
}