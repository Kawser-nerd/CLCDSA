using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;


class Program
{
    static void Main(string[] Args) {
        var lis = new List<string>(ReadLine().Split(' ')).Select(int.Parse).ToList();

        int Result = 0;

        for (int X = 0; X <= lis[0]; X++)
            for (int Y = 0; Y <= lis[0]; Y++)
                if (0 <= lis[1] - X - Y && lis[1] - X - Y <= lis[0])
                    Result++;

        WriteLine(Result);

        ReadLine();
    }
}