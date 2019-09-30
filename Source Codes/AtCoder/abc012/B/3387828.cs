using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static string cin()
    {
        var result = "";
        while (true)
        {
            int tmp = Read();
            if (tmp < 0 || String.IsNullOrWhiteSpace((char)tmp + ""))
                break;
            if (tmp != '\r')
                result += (char)tmp;
        }
        return result;
    }

    static void Main()
    {
        int N = int.Parse(cin());
        var hms = new List<int>();

        for (int i = 0; i < 3; i++)
        {
            hms.Add(N % 60);
            N /= 60;
        }

        for (int i = 2; i >= 0; i--)
        {
            int j = hms[i];
            if (j < 10)
                Write(0);
            Write(j);
            if (i != 0)
                Write(':');
        }
        WriteLine();
    }
}