using System;
using System.Globalization;
using System.IO;

namespace ABC119A_2
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length > 0)
            {
                Console.SetIn(new StreamReader(args[0]));
            }

            new Program().Solve();
        }

        void Solve()
        {
            var date = DateTime.Parse(Console.ReadLine());
            var last = DateTime.Parse("2019/04/30");
            Console.Error.WriteLine(date);
            Console.Error.WriteLine(last);

            if (date.Date <= last.Date)
            {
                Console.WriteLine("Heisei");
            }
            else
            {
                Console.WriteLine("TBD");
            }
        }
    }
}