using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        var num = int.Parse(Console.ReadLine());

        var list = new List<int>(num);

        for(int i = 0; i < num; ++i)
        {
            list.Add(int.Parse(Console.ReadLine()));
        }

        list.Sort( (A, B) =>
        {
            return B - A;
        });

        list[0] = list[0] / 2;

        Console.WriteLine(list.Sum());
    }
}