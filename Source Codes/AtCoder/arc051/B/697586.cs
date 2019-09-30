using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
 
class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        List<int> primeNumberList = this.CreatePrimeNumberList();
 
        int cnt = int.Parse(Reader.ReadLine());
 
        if (cnt == 1)
        {
            Console.WriteLine("1 1");
        }
        else
        {
            int a = 2;
            int b = 3;
 
            for (int i = 0; i < cnt - 2; i++)
            {
                int tmp = a + b;
                a = b;
                b = tmp;
            }
 
            Console.WriteLine(b + " " + a);
        }
    }
 
    private int callCount = 0;
    private int Gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        callCount++;
        return this.Gcd(b, a % b);
    }
 
    private List<int> CreatePrimeNumberList()
    {
        bool[] flags = new bool[101];
 
        List<int> primeNumber = new List<int>();
 
        for (int i = 2; i < flags.Length; i++)
        {
            if (!flags[i])
            {
                primeNumber.Add(i);
                for (int j = 1; j <= 100 / i; j++)
                {
                    flags[i * j] = true;
                }
            }
        }
        return primeNumber;
 
 
    }
 
 
 
 
 
    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"
2
 
";
        private static System.IO.StringReader Sr = null;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (Sr == null)
                {
                    Sr = new System.IO.StringReader(PlainInput.Trim());
                }
                return Sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
        public static int[] GetInt(char delimiter = ' ', bool trim = false)
        {
            string inptStr = ReadLine();
            if (trim)
            {
                inptStr = inptStr.Trim();
            }
            string[] inpt = inptStr.Split(delimiter);
            int[] ret = new int[inpt.Length];
            for (int i = 0; i < inpt.Length; i++)
            {
                ret[i] = int.Parse(inpt[i]);
            }
            return ret;
        }
    }
    static void Main()
    {
        Program prg = new Program();
        prg.Proc();
    }
}