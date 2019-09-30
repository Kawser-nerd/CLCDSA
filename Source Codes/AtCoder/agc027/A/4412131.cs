using System;
    using System.Collections.Generic;
    using static System.Console;
    using System.Linq;


class Program
{

    static void Main(string[] Args) {
        var Nx = new List<string>(ReadLine().Split(' ')).Select(ele => Int32.Parse(ele)).ToList();
        var a = new List<string>(ReadLine().Split(' ')).Select(ele => Int32.Parse(ele)).ToList();
        int Result = 0;

        while (true) {
            int min = a.Min();
            if (min <= Nx[1]) {
                a.Remove(min);
                Nx[1] -= min;
                Result++;
            } else break;
            if(a.Count() == 0) {
                if (Nx[1] != 0) Result--;
                break;
            }
        }

        WriteLine(Result);

        ReadLine();
    }
}