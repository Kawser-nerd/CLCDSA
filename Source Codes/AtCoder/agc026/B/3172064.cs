using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using static System.Console;
using static System.Math;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Xml;
using static MyIO.Cin;

class Program
{
    static int N;
    static void Solve()
    {
        N = NI();
        for (int i = 0; i < N; i++)
        {
            long A = NL();
            long B = NL();
            long C = NL();
            long D = NL();
            if (A < B || D < B)
            {
                Console.WriteLine("No"); continue;
            }
            else if (C >= B)
            {
                Console.WriteLine("Yes"); continue;
            }
            //C < ? < B,D ?????????????
            long g = Gcd(B, D);
            long a = A % g;
            //a + gp??????
            //C?????????
            long upc = a + Ceil(C - a+1, g) * g;
            if (C < upc && upc < B && upc < D)
            {
                Console.WriteLine("No");
            }
            else
            {
                Console.WriteLine("Yes");
            }
        }
    }
    static int Gcd(int a, int b)
    {
        return b == 0 ? a : Gcd(b, a % b);
    }
    static long Gcd(long a, long b)
    {
        return b == 0 ? a : Gcd(b, a % b);
    }
    static int Ceil(int a, int b)
    {
        return (a + b - 1) / b;
    }
    static long Ceil(long a, long b)
    {
        return (a + b - 1) / b;
    }
    static void Main(string[] args)
    {
        var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
        Console.SetOut(sw);
        Solve();
        Console.Out.Flush();
    }

}


namespace MyIO
{
    using System;
    using System.Text;
    using System.Globalization;

    public static class Cin
    {
        public static string NextToken()
        {
            StringBuilder tokenChars = new StringBuilder();
            bool tokenFinished = false;
            bool skipWhiteSpaceMode = true;
            while (!tokenFinished)
            {
                int nextChar = Console.Read();
                if (nextChar == -1)
                {
                    tokenFinished = true;
                }
                else
                {
                    char ch = (char)nextChar;
                    if (char.IsWhiteSpace(ch))
                    {
                        if (!skipWhiteSpaceMode)
                        {
                            tokenFinished = true;
                            if (ch == '\r' && (Environment.NewLine == "\r\n"))
                            {
                                Console.Read();
                            }
                        }
                    }
                    else
                    {
                        skipWhiteSpaceMode = false;
                        tokenChars.Append(ch);
                    }
                }
            }

            string token = tokenChars.ToString();
            return token;
        }

        public static int NI()
        {
            string token = Cin.NextToken();
            return int.Parse(token);
        }
        public static long NL()
        {
            string token = Cin.NextToken();
            return long.Parse(token);
        }
        public static double ND(bool acceptAnyDecimalSeparator = true)
        {
            string token = Cin.NextToken();
            if (acceptAnyDecimalSeparator)
            {
                token = token.Replace(',', '.');
                double result = double.Parse(token, CultureInfo.InvariantCulture);
                return result;
            }
            else
            {
                double result = double.Parse(token);
                return result;
            }
        }
        public static decimal NextDecimal(bool acceptAnyDecimalSeparator = true)
        {
            string token = Cin.NextToken();
            if (acceptAnyDecimalSeparator)
            {
                token = token.Replace(',', '.');
                decimal result = decimal.Parse(token, CultureInfo.InvariantCulture);
                return result;
            }
            else
            {
                decimal result = decimal.Parse(token);
                return result;
            }
        }
        public static int[] NIA(int N)
        {
            int[] a = new int[N];
            for (int i = 0; i < N; i++)
                a[i] = NI();
            return a;
        }

    }
}