using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int len = int.Parse(Reader.ReadLine());

        int[] line1 = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        int[] line2 = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();

        int[] line1total = new int[len];
        line1total[0] = line1[0];
        for (int i = 1; i < line1.Length; i++) {
            line1total[i] = line1[i] + line1total[i - 1];
        }
        int[] line2total = new int[len];
        line2total[len - 1] = line2.Last();
        for (int i = len - 2; i >= 0; i--) {
            line2total[i] = line2[i] + line2total[i + 1];
        }
        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans = Math.Max(ans, line1total[i] + line2total[i]);
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





1
2
3

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