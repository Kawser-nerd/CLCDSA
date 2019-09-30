using System;

class AtCoder
{    
    static void Main(string[] args)
     {
        int n = int.Parse(Console.ReadLine());
        int a = int.Parse(Console.ReadLine());

        int amari = n % 500;

        var s = amari <= a ? "Yes" : "No";

        Console.WriteLine(s);
     }
 }