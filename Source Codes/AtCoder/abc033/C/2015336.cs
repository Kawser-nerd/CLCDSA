using System;
    using System.Collections.Generic;
    using System.Linq;
    using static Atcoder;
    using System.Threading.Tasks;
    using System.ComponentModel;
     
    public class Hello
    {
     
        public static void Main()
        {
            string[] s = Console.ReadLine().Split('+');
            int count = 0;
            for(int i = 0;i < s.Length;i++){
                if(!s[i].Contains("0"))count++;
            }
            Console.WriteLine(count);
        }
    }
     
    public class Atcoder
    {
    static void Swap<T>(ref T a, ref T b)
    {
    var t = a;
    a = b;
    b = t;
    }
    public static int LCM(int a, int b)
    {
    int c = a * b;
    if (a < b) Swap(ref a, ref b);
    int d = a % b;
    while (d != 0)
    {
    a = b;
    b = d;
    d = a % b;
    }
    return c / b;
    }
    public static string strReverse(string s)
    {
    return new string(s.Reverse().ToArray());
    }
    public static int Cin()
    {
    return int.Parse(Console.ReadLine());
    }
    public static bool IsPrime(int n)
    {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
     
    //double sqrtNum = Math.Sqrt(n);
    for (int i = 3; i < n; i += 2)
    {
    if (n % i == 0) return false;
    }
    return true;
    }
    public static string[] SpRead(char c)
    {
    return Console.ReadLine().Split(c);
    }
    }