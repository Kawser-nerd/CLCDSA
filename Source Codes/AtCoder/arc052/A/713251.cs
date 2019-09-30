using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine().ToCharArray();
            int begin = 0;
            int tmp = 0;
            while (!int.TryParse(s[begin].ToString(), out tmp)) begin++;
            int end = begin;
            if(end < s.Length - 1)
            {
                if (int.TryParse(s[end+1].ToString(), out tmp))
                {
                    end++;
                }
            } 

            var result = begin == end ? s[begin].ToString() : string.Format("{0}{1}", s[begin], s[end]);
            Console.WriteLine(result);
        }
    }
}