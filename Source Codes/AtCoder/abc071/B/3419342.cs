using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace _20180502_pra
{
    class Program
    {
        static void Main(string[] args)
        {

           var S = Console.ReadLine().ToArray();
            Array.Sort(S);
            char[] charS = S.ToArray();

            for (int i = 'a'; i <= 'z'; i++)
            {
                var contains = S.Contains((char)i);
                if (!contains)
                {
                    Console.WriteLine((char)i);
                    return;
                }
               
            }
            Console.WriteLine("None");

        }
    }
}