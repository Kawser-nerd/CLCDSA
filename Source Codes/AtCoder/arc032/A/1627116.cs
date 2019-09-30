using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;

using static System.Console;

namespace F0rEsM8
{
    class MainClass
    {

        public static void Main (string[] args)
        {
            var n = int.Parse (ReadLine ());
            var sums = Enumerable
                .Range (1, n)
                .Sum ();

            WriteLine ((IsPrime (sums)) ? "WANWAN" : "BOWWOW");


        }

        public static bool IsPrime (int n)
        {
            if (n < 2) return false;
            else if (n == 2) return true;
            else if (n % 2 == 0) return false;

            var sqrtN = Math.Sqrt (n);
            for (int i = 3; i <= sqrtN; i++)
            {
                if (n % i == 0) return false;
            }

            return true;
        }
    }



    public class Scanner
    {
        private StreamReader Sr;
        private string[] S;
        private int Index;
        private const char Separator = ' ';
        public Scanner (Stream source)
        {
            Index = 0;
            S = new string[0];
            Sr = new StreamReader (source);
        }
        private string[] Line ()
        {
            return Sr.ReadLine ().Split (Separator);
        }

        public string Next ()
        {
            string result;
            if (Index >= S.Length)
            {
                S = Line ();
                Index = 0;
            }
            result = S[Index];
            Index++;
            return result;
        }
        public int NextInt ()
        {
            return int.Parse (Next ());
        }
        public double NextDouble ()
        {
            return double.Parse (Next ());
        }
        public long NextLong ()
        {
            return long.Parse (Next ());
        }
        public decimal NextDecimal ()
        {
            return decimal.Parse (Next ());
        }
        public string[] StringArray (int index = 0)
        {
            Next ();
            Index = S.Length;
            return S.Skip (index).ToArray ();
        }
        public int[] IntArray (int index = 0)
        {
            return StringArray (index).Select (int.Parse).ToArray ();
        }
        public long[] LongArray (int index = 0)
        {
            return StringArray (index).Select (long.Parse).ToArray ();
        }
        public bool EndOfStream
        {
            get { return Sr.EndOfStream; }
        }
    }
}