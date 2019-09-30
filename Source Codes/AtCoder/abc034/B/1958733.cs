using System;
using System.Linq;
using System.Collections.Generic;

public class Hello
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        if(n % 2 == 1)Console.WriteLine(n+1);
        else Console.WriteLine(n-1);
    }
}