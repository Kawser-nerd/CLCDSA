using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int nikuCount = int.Parse(Reader.ReadLine());

        int[] niku = new int[nikuCount];
        for (int i = 0; i < nikuCount; i++) {
            niku[i] = int.Parse(Reader.ReadLine());
        }

        int ans = int.MaxValue;
        for (int i = 0; i <= 15; i++) {
            int nikuA = 0;
            int nikuB = 0;
            for (int j = 0; j < nikuCount; j++) {
                int key = 1 << j;
                if((i&key)==0) {
                    nikuA += niku[j];
                } else {
                    nikuB += niku[j];
                }
            }
            ans = Math.Min(ans, Math.Max(nikuA, nikuB));
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


4
4
6
7
10


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