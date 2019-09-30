using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();

        int itemCount = inpt[0];
        int len = inpt[1];

        int[] items = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();

        int ans = 0;
        for (int i = 0; i < itemCount; i+=len-1) {
            ans++;
            if(i == itemCount - 1) {
                ans--;
            }
        }

        Console.WriteLine(ans);
    }

    public class Reader
    {
        static StringReader sr;
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
 
 
8 3
7 3 1 8 4 6 2 5
 
 
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