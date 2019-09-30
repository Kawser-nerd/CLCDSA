using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        int[] inpt = Reader.GetInt();

        int x1 = inpt[0];
        int y1 = inpt[1];
        int r = inpt[2];

        inpt = Reader.GetInt();

        int x2 = inpt[0];
        int y2 = inpt[1];
        int x3 = inpt[2];
        int y3 = inpt[3];

        // ?????????
        List<int[]> pos4 = new List<int[]>();
        pos4.Add(new int[] { x2, y2 });
        pos4.Add(new int[] { x2, y3 });
        pos4.Add(new int[] { x3, y2 });
        pos4.Add(new int[] { x3, y3 });

        bool isAllIn = true;
        pos4.ForEach((pos) =>
        {
            double tmp = Math.Pow(x1 - pos[0], 2) + Math.Pow(y1 - pos[1], 2);
            if (tmp > r * r)
            {
                isAllIn = false;
            }
        });

        bool hasBlue = !isAllIn;
        if (x2 == x3 || y2 == y3)
        {
            hasBlue = false;
        }
       

        // ?????????
        isAllIn = true;
        List<int> yLine = new List<int>();
        yLine.Add(y1 + r);
        yLine.Add(y1 - r);
        yLine.ForEach((a) =>
        {
            if (a >= Math.Min(y2, y3) && a <= Math.Max(y2, y3))
            {

            }
            else
            {
                isAllIn = false;
            }
        });
        List<int> xLine = new List<int>();
        xLine.Add(x1 + r);
        xLine.Add(x1 - r);
        xLine.ForEach((a) => {
            if (a >= Math.Min(x2, x3) && a <= Math.Max(x2, x3))
            {

            }
            else
            {
                isAllIn = false;
            }
        });
        bool hasRed = !isAllIn;

        Console.WriteLine(hasRed ? "YES" : "NO");
        Console.WriteLine(hasBlue ? "YES" : "NO");

    }





    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"

0 0 5
-4 -4 4 4
 
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
        public static int[] GetInt(char delimiter = ' ', bool trim = false)
        {
            string inptStr = ReadLine();
            if (trim)
            {
                inptStr = inptStr.Trim();
            }
            string[] inpt = inptStr.Split(delimiter);
            int[] ret = new int[inpt.Length];
            for (int i = 0; i < inpt.Length; i++)
            {
                ret[i] = int.Parse(inpt[i]);
            }
            return ret;
        }
    }
    static void Main()
    {
        Program prg = new Program();
        prg.Proc();
    }
}