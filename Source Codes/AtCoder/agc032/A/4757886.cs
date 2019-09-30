using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            label:
            var a = A();
            if (a == null)
            {
                WriteLine(-1);
            }
            else
            {
                foreach(var n in a)
                {
                    WriteLine(n);
                }
            }
        }

        static List<int> A()
        {
            var list = new List<int>();
            ReadLine();
            var li2 = ReadLine().Split(' ').Select(int.Parse).ToList();
            while (li2.Count > 0)
            {
                int i = li2.Count - 1;
                for (; 0 <=i; --i)
                {
                    if (li2[i] == i + 1)
                    {
                        list.Add(i + 1);
                        li2.RemoveAt(i);
                        break;
                    }
                }
                if (i < 0) return null;
            }
            list.Reverse();
            return list;
        }
    }
}