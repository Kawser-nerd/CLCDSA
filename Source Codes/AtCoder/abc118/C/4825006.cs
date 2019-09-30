using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


public class MathLib
{
    /// <summary>
    /// ?????????
    /// </summary>
    public static long Gcd(long a, long b)
    {
        return (a < b) ? Gcd(b, a)
             : (b > 0) ? Gcd(b, a % b)
                       : a;
    }

    /// <summary>
    /// ?????????
    /// </summary>
    public static long Lcm(long a, long b)
    {
        return a / Gcd(a, b) * b;
    }
}

class Program
{
    static int N;
    static int[] A;

    public static void Main(string[] args)
    {
        MainModule(Console.In);
    }

    public static void MainModule(TextReader In)
    {
        {
            var lin = In.ReadLine().Split(' ').Select(n => int.Parse(n)).ToArray();
            N = lin[0];
        }
        A = In.ReadLine().Split(' ').Select(n => int.Parse(n)).ToArray();

        int prev = A[0];
        for (int i = 1; i < N; i++)
        {
            prev = (int)MathLib.Gcd(prev, A[i]);
        }

        Console.WriteLine(prev);
    }
}