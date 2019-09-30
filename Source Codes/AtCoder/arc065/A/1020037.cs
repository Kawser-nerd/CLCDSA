using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {

        static string[] s3 = { "dreamer", "dream", "eraser", "erase" };
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            if (f(s,0))
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }

        }

        static bool f(string s,int index)
        {
            while (true)
            {
                if (index == s.Length) return true;
                var next = s3.Where(str =>
                {
                    var a = s.IndexOf(str, index, Math.Min(7, s.Length - index));
                    return a == index;
                }).ToArray();
                if (next.Length == 1)
                {
                    index += next[0].Length;
                    continue;
                }
                for (int i = 0; i < next.Length; i++)
                {
                    if (f(s,index+next[i].Length))
                    {
                        return true;
                    }
                }
                return false;

            }
        }

    }
}