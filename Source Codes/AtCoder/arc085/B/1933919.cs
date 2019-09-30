using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        long[] inpt = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();
        int cardCount = (int)inpt[0];

        long xPoint = inpt[1];
        long yPoint = inpt[2];

        inpt = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();
        long ans = 0;
        if(cardCount==1) {
            ans = Math.Abs(inpt[0] - yPoint);
        } else {
            ans = Math.Max(Math.Abs(inpt.Last() - yPoint), Math.Abs(inpt[inpt.Length - 2] - inpt.Last()));
        }
        Console.WriteLine(ans);
    }

    public class Reader
    {
        private static StringReader sr;
        public static bool IsDebug = false;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (sr == null)
                {
                    sr = new StringReader(InputText.Trim());
                }
                return sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
        private static string InputText = @"





3 100 100
10 1000 100




";
    }

    public static void Main(string[] args)
    {
#if DEBUG
        Reader.IsDebug = true;
#endif
        Program prg = new Program();
        prg.Proc();
    }
}