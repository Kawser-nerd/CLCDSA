using System;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var sct = 0;
        for(var i = 0; i < str.Length; i++)
            if (str[i] == 'S')
                sct++;
            else if (sct > 0)
                sct--;
        WriteLine(sct * 2);
    }
}