using static System.Console;
using System;

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
        var S = cin();

        var i = 0;
        foreach (char c in S)
        {
            if (i == 0)
                Write(c.ToString().ToUpper());
            else
                Write(c.ToString().ToLower());
            i++;
        }
        WriteLine();
    }
}