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
        var input = ReadLine().Split(' ');
        var a = input[0];
        var b = input[1];
        if (a[0] != '9'||b[0]!='1')
        {
            var difa = 9 - ToInt32(a.Substring(0,1));
            var difb = ToInt32(b.Substring(0,1))-1;
            if (difa > difb)
                a = "9" + a[1] + a[2];
            else b = "1" + b[1] + b[2];
        }
        else
        {
            for(var i = 1; i < 3; i++)
                if (a[i] != '9' || b[i] != '0')
                {
                    var difa = 9 - ToInt32(a.Substring(i,1));
                    var difb = ToInt32(b.Substring(i,1)) - 1;
                    if (difa > difb)
                    {
                        var v = "";
                        for (var j = 0; j < 3; j++)
                            if (j == i)
                                v += '9';
                            else v += a[j];
                        a = v;
                    }
                    else
                    {
                        var v = "";
                        for (var j = 0; j < 3; j++)
                            if (j == i)
                                v += '0';
                            else v += b[j];
                        b = v;
                    }
                    WriteLine(ToInt32(a) - ToInt32(b));
                    return;
                }
        }
        WriteLine(ToInt32(a) - ToInt32(b));
    }
}