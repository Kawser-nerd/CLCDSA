using System;
using System.Linq;
using System.Collections.Generic;

class A{
    static void Main(){
        var input = new List<List<int>>();

        for(var i = 0; i < 3; i++)
        {
            input.Add(Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList());
        }

        var count = 0;
        foreach (var item in input)
        {
            count += item[0] * item[1] / 10;
        }

        Console.WriteLine(count);
    }
}