using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        long[] inpt = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();

        int count = (int)inpt[0];
        long addTime = inpt[1];

        inpt = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();

        long ans = 0;

        long tmpTime = addTime;

        for (int i = 1; i < count; i++)
        {
            if (inpt[i] - inpt[i-1] < tmpTime)
            {
                ans += (inpt[i] - inpt[i-1]);
                tmpTime = addTime;
            }
            else
            {
                ans += tmpTime;
                tmpTime = addTime;
            }
        }
        ans += tmpTime;
        Console.WriteLine(ans);

        
    }



    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"



9 10
0 3 5 7 100 110 200 300 311


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
    }
    static void Main()
    {
        Program prg = new Program();
        prg.Proc();
    }
}