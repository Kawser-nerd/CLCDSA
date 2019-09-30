using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
        var st = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var bul = new StringBuilder();
        for (var j = 0; j < 2; j++)
        {
            for (var i = st[0] + 1; i <= st[2]; i++)
                if (j == 0)
                    bul.Append("R");
                else bul.Append("L");
            for (var i = st[1] + 1; i <= st[3]; i++)
                if (j == 0) bul.Append("U");
                else bul.Append("D");
        }
        
        for(var j = 0; j < 2; j++)
        {
            if (j == 0) bul.Append("D");
            else bul.Append("U");
            for (var i = st[0]; i <= st[2]; i++)
                if (j == 0) bul.Append("R");
                else bul.Append("L");
            for (var i = st[1]; i <= st[3]; i++)
                if (j == 0) bul.Append("U");
                else bul.Append("D");
            if (j == 0) bul.Append("L");
            else bul.Append("R");
        }
        WriteLine(bul.ToString());
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}