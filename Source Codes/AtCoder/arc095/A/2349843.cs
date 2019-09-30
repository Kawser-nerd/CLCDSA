using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int itemCount = int.Parse(Reader.ReadLine());
        int[] items = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();

        int[] ordered = items.OrderBy(a => a).ToArray();
        int center1 = ordered[ordered.Length / 2 - 1];
        int center2 = ordered[ordered.Length / 2];

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < itemCount; i++) {
            if(center1 == center2) {
                ans.AppendLine(center1.ToString());
                continue;
            } 
            if(items[i]<= center1) {
                ans.AppendLine(center2.ToString());
            } else {
                ans.AppendLine(center1.ToString());
            }
        }
        Console.Write(ans.ToString());
         
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


6
5 5 4 4 3 3



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