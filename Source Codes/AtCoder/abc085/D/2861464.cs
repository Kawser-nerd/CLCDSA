using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        string[] input;
        input = ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int H = int.Parse(input[1]);
        var attacks = new List<Tuple<int, int>>();
        for(int i = 0; i<N; i++)
        {
            input = ReadLine().Split(' ');
            attacks.Add(new Tuple<int, int>(int.Parse(input[0]), int.Parse(input[1])));
        }

        var max = attacks.Max(x => x.Item1);
        int count = 0;
        int h = H;
        foreach(var item in attacks.OrderByDescending(x => x.Item2).Where(x => x.Item2 > max))
        {
            count++;
            h -= item.Item2;
            if(h <= 0)
            {
                WriteLine(count);
                return;
            }
        }

        count += (int)Math.Ceiling((double)h / (double)max);
        WriteLine(count);
    }
}