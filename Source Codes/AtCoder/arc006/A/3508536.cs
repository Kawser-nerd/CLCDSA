using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var st = ReadLine().Split(' ');
        var bonu = ReadLine();
        var re = ReadLine().Split(' ');
        var count = 0;
        foreach (var r in re)
            if (st.Contains(r)) count++;
        switch (count)
        {
            case 6:
                WriteLine(1);
                break;
            case 5:
                WriteLine(re.Contains(bonu) ? 2 : 3);
                break;
            case 4:
                WriteLine(4);
                break;
            case 3:
                WriteLine(5);
                break;
            default:
                WriteLine(0);
                break;
        }
    }
}