using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B._754
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] arr = Console.ReadLine().ToCharArray();

            int min = int.MaxValue;
            int res;

            for (int i = 0; i < arr.Length - 3 + 1; i++)
            {
                res = Math.Abs(753 - int.Parse(new string(arr.Skip(i).Take(3).ToArray())));
                min = min > res ? res : min;
            }

            Console.WriteLine(min);
        }
    }
}