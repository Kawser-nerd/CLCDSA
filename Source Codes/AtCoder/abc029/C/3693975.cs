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
        var num = ToInt32(ReadLine());
        for (var i = 0; i < 3; i++)
            Get("", i, num);
    }
    private static void Get(string pass,int index,int length)
    {
        string pa = "abc";
        pass += pa[index];
        if (pass.Length == length)  WriteLine(pass); 
        else
            for (var i = 0; i < 3; i++)
                Get(pass, i, length);
    }
}