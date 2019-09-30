using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

    public class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(program1(new String[] { Console.ReadLine() }));
        }

        public static string program1(string[] args)
        {
            var sc = args[0].Split(' ').Select(long.Parse);
            var s = sc.First();
            var c = sc.Last();

            if (s * 2L <= c)
            {
                return (s + (c - s * 2L) / 4L) + "";
            }
            else
            {
                return (c / 2L) + "";
            }
        }
    }