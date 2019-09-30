using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int target = int.Parse(Reader.ReadLine());
        StringBuilder ans = new StringBuilder();

        ans.AppendLine("1");
        long current = 1;
        for (int i = 1; i < target; i++) {
            current = GetAns(++current);
            ans.AppendLine(current.ToString());
        }
        Console.Write(ans.ToString());
    }


    private long GetAns(long baseNum) {
        string numStr = baseNum.ToString();
        int keta = numStr.Length;


        long maxSi = long.Parse(string.Empty.PadLeft(keta, '9'));
        long maxBo = 9 * keta;
        List<long> boList = new List<long>();
        List<long> siList = new List<long>();
        for (int i = 0; i <= keta; i++) {
            string tmp = numStr.Substring(0, keta - i) + string.Empty.PadLeft(i, '9');
            long si = long.Parse(tmp);
            long bo = tmp.Select(a => long.Parse(a.ToString())).Sum();

            while(boList.Count > 0 && si*boList.Last() < siList.Last()*bo) {
                boList.RemoveAt(boList.Count - 1);
                siList.RemoveAt(siList.Count - 1);
            }

            if(si*maxBo <= maxSi*bo) {
                boList.Add(bo);
                siList.Add(si);
            }
        }
        return siList.First();
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