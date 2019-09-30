using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;



class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        int inputCount = int.Parse(Reader.ReadLine());
        Dictionary<long, int> list = new Dictionary<long, int>();
        for(int i=0; i<inputCount; i++) {
            long num = long.Parse(Reader.ReadLine());
            list.Add(num, i);
        }
        List<KeyValuePair<long, int>> orderd = list.OrderBy(a=>a.Key).ToList();
        int cnt = 0;
        for(int i=0; i<orderd.Count; i++) {
            if((i-orderd[i].Value) % 2 != 0) {
                cnt++;
            }
        }
        Console.WriteLine(cnt / 2);
    }

    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"

5
10
8
5
3
2

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