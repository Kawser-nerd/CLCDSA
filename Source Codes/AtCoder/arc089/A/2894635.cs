using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
        var N = int.Parse(Console.ReadLine());
        for (int i = 0; i < N; i++)
        {
            var array = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            //2??????
            if (array[0] - array[1] - array[2] < 0 || (array[0] - array[1] - array[2]) % 2 != 0)
            {
                Console.WriteLine("No");
                return;
            }
        }
        Console.WriteLine("Yes");
    }
}