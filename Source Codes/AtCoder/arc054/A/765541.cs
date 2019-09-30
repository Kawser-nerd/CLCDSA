using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ARC_cs
{
    class Program
    {
        static void entry(bool DEBUG)
        {
            if (DEBUG)
            {
                var test_input = System.IO.Directory.GetFiles(@"..\..\").Where(name => name.EndsWith(@".txt"));
                foreach (var f in test_input)
                {
                    using (var s = new System.IO.StreamReader(f, Encoding.UTF8))
                    {
                        var sw = new System.Diagnostics.Stopwatch();
                        Console.WriteLine("input----------------------------------------------------\n");
                        Console.WriteLine(System.IO.Path.GetFileName(f));
                        Console.WriteLine("\noutput---------------------------------------------------\n");
                        sw.Start();
                        main(s);
                        sw.Stop();
                        Console.WriteLine("\ntime-----------------------------------------------------\n");
                        Console.WriteLine(sw.Elapsed);
                        Console.WriteLine("\n---------------------------------------------------------");
                    }
                }
            }
            else
            {
                using (var s = Console.In)
                {
                    main(s);
                }
            }
        }

        static void Main(string[] args)
        {
            //TODO: DEBUG -> false
            bool DEBUG = false;
            entry(DEBUG);
        }

        static void main(System.IO.TextReader s)
        {
            var input = s.ReadLine().Split(' ').Select(i => int.Parse(i)).ToArray();

            int fd = (input[0] + input[4] - input[3]) % input[0];
            int bd = input[0] - fd;
            int fv = input[2] + input[1];
            int bv = input[2] - input[1];
            bool forward = fv > 0;
            bool back = bv > 0;

            double a, b;
            a = b = input[0] + 1;
            if (forward)
            {
               a = (double)fd / fv;
            }
            if (back)
            {
               b = (double)bd / bv;
            }

            double ans = Math.Min(a, b);

            Console.WriteLine(string.Format("{0}", ans));
        }
    }
}