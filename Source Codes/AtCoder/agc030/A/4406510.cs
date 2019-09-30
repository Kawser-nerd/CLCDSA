using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;


class Program
{

    static void Main(string[] Args) {
        var list = new List<string>(ReadLine().Split(' ')).Select(ele => Int32.Parse(ele)).ToList();

        int Result = 0;
        if(list[0] + list[1] < list[2]) {
            Result += list[0] + list[1] + 1;
        } else {
            Result += list[2];
        }
        Result += list[1];
        WriteLine(Result);

        ReadLine();
    }
}