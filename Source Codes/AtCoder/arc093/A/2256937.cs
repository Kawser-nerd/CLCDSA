using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {

        int inputCount = int.Parse(Reader.ReadLine());

        List<int> points = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToList();
        points.Add(0);
        points.Insert(0, 0);

        long total = 0;
        for (int i = 1; i < points.Count; i++) {
            total += Math.Abs(points[i - 1] - points[i]);
        }
        int prev = 0;

        StringBuilder ans = new StringBuilder();
        for (int i = 2; i < points.Count; i++) {
            int temp1 = Math.Abs(prev - points[i - 1]) + Math.Abs(points[i-1] - points[i]);
            int temp2 = Math.Abs(prev - points[i]);
            ans.AppendLine((total - (temp1 - temp2)).ToString());
            prev = points[i - 1];
        }
        Console.WriteLine(ans.ToString());

    
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
-679 -2409 -3258 3095 -3291 -4462

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