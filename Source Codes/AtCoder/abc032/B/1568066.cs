using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = ReadLine();
            int k = int.Parse(ReadLine());
            int cnt = 0;
            List<string> items = new List<string>();
            while (cnt + k < s.Length+1)
            {
                string buf = s.Substring(cnt, k);
                if (!items.Contains(buf))
                    items.Add(buf);
                cnt++;
            }
        
            WriteLine(items.Count);
            ReadLine();
        }
    }
}