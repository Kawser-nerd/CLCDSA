using System;
using System.Linq;

namespace arc007_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int listeningCD = 0;
            int[] CDs = new int[x[0]];
            for (int i = 0; i < x[0]; i++)
            {
                CDs[i] = i + 1;
            }
            int disk;
            for (int i = 0; i < x[1]; i++)
            {
                if ((disk = int.Parse(Console.ReadLine())) != listeningCD)
                {
                    CDs[Array.IndexOf(CDs, disk)] = listeningCD;
                    listeningCD = disk;
                }
            }
            for (int i = 0; i < x[0]; i++)
            {
                Console.WriteLine(CDs[i]);
            }
        }
    }
}