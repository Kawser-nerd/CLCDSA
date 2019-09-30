using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

public class Program
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int ans = (n / 10) * 100;
        if (n % 10 > 6) ans += 100;
        else ans += (n % 10) * 15;
        Console.WriteLine(ans);
    }
}