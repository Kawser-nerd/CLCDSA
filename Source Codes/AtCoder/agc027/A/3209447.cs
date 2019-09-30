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

        this.Kodomo = new long[(int)inpt[0]];

        long totalOkasi = inpt[1];

        this.Kodomo = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).OrderBy(s=>s).ToArray();

        int ans = 0;

        foreach(int k in Kodomo) {
            if(totalOkasi < k) {
                totalOkasi = 0;
                break;
            }
            totalOkasi -= k;
            ans++;
        }
        if(totalOkasi > 0) {
            ans--;
        }
        Console.WriteLine(ans);
    }


    private long[] Kodomo;

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



2 10
20 20

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