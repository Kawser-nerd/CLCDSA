using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        long inpt = long.Parse(Reader.ReadLine());

        long ans = (inpt / 11)*2;

        if (inpt % 11 > 6)
        {
            ans+=2;
        }
        else if (inpt % 11 > 0)
        {
            ans++;
        }
        Console.WriteLine(ans);




    }




    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"




149696127901




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