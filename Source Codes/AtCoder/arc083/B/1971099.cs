using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int matiCount = int.Parse(Reader.ReadLine());
        long[,] Road = new long[matiCount, matiCount];
        for (int i = 0; i < matiCount; i++) {
            long[] inpt = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();
            for (int j = 0; j < matiCount;j++) {
                Road[i, j] = inpt[j];
            }
        }

        bool[,] IsFuyo = new bool[matiCount, matiCount];
        for (int i = 0; i < matiCount; i++) {
            for (int j = 0; j < matiCount; j++) {
                if(i==j) {
                    continue;
                }
                for (int k = 0; k < matiCount; k++) {
                    if(i==k||j==k) {
                        continue;
                    }
                    long direct = Road[j, k];
                    long conn = Road[j, i] + Road[i, k];
                    if(direct>conn) {
                        Console.WriteLine(-1);
                        return;
                    }
                    if(direct==conn) {
                        IsFuyo[j, k] = true;
                    }
                }
            }
        }
        long ans = 0;
        for (int i = 0; i < matiCount; i++) {
            for (int j = 0; j < matiCount; j++) {
                if(!IsFuyo[i,j]) {
                    ans += Road[i, j];
                }
            }
        }
        Console.WriteLine(ans / 2);
    
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


5
0 21 18 11 28
21 0 13 10 26
18 13 0 23 13
11 10 23 0 17
28 26 13 17 0


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