using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class A
    {
        private string inPath = @"D:\GoogleRound3\ConsoleApplication1\A-small-attempt1 (1).in";
        private string outPath = @"D:\GoogleRound3\ConsoleApplication1\A.out";


        int GetBase(char[] array)
        {
            Dictionary<char, int> dic = new Dictionary<char, int>();
            for (int i = 0; i < array.Length; ++i)
            {
                if (!dic.ContainsKey(array[i]))
                    dic.Add(array[i], 0);
            }
            return dic.Count;
        }
        private long GetResult(string str)
        {
            char[] array = str.ToCharArray();
            Dictionary<char, int> dic = new Dictionary<char, int>();
            for (int i = 0; i < array.Length; ++i)
            {
                if (!dic.ContainsKey(array[i]))
                    dic.Add(array[i], -1);
            }
            int b = dic.Count;
            int curV = 0;
            dic[array[0]] = 1;
            for (int i = 1; i < array.Length; ++i)
            {
                if (dic[array[i]] == -1)
                {
                    dic[array[i]] = curV;
                    if (curV == 0)
                        curV = 2;
                    else
                        curV++;
                }
            }
            long ret = 0;
            if (b == 1)
                b = 2;
            for (int i = array.Length - 1, f = 1; i >= 0; --i, f*=b)
            {
                ret += f * dic[array[i]];
            }
            return ret;
        }
        public void Run()
        {
            StreamReader sr = new StreamReader(inPath);
            string line = sr.ReadLine();
            int tc = int.Parse(line);

            StreamWriter sw = new StreamWriter(outPath);

            for (int t = 1; t <= tc; ++t)
            {
                line = sr.ReadLine();
                long ret = GetResult(line);
                sw.WriteLine("Case #{0}: {1}",t,ret);
                sw.Flush();
            }
            sw.Close();
        }
    }
}
