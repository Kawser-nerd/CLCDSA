using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int boxCount = int.Parse(Reader.ReadLine());

        List<int> list = new List<int>();
        for (int i = 0; i < boxCount; i++) {
            int box = int.Parse(Reader.ReadLine());
            if(list.Any(a=>a>=box)) {
                int target = list.Where(a => a >= box).Min();
                int idx = list.IndexOf(target);
                list[idx] = box;
            } else {
                list.Add(box);
            }
        }
        Console.WriteLine(list.Count());
    
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




15
3
1
4
1
5
9
2
6
5
3
5
8
9
7
9



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