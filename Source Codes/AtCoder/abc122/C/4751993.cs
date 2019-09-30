using System;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace Get_AC
{
    class Program
    {
        public static void Main(string[] args)
        {
            using (var sc = new SetConsole())
            {
                var nq = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var str = Console.ReadLine();

                var array = Enumerable.Repeat(0, nq[0] + 1).ToArray();
                for (int i = 0; i < nq[0] - 1; i++)
                {
                    if (str[i] == 'A' && str[i + 1] == 'C')
                    {
                        array[i + 1] = array[i] + 1;
                    }
                    else
                    {
                        array[i + 1] = array[i];
                    }
                }
                for (int i = 0; i < nq[1]; i++)
                {
                    var lr = Console.ReadLine().Split().Select(int.Parse).ToArray();
                    Console.WriteLine(array[lr[1] - 1] - array[lr[0] - 1]);
                }
            }
        }

    }

    class SetConsole : IDisposable
    {
        public SetConsole()
        {
            var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            Console.SetOut(sw);
        }
        public void Dispose() { Console.Out.Flush(); }
    }
}