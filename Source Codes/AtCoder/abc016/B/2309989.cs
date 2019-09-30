using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] abc = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            bool plus = false;
            bool minus = false;
            if (abc[0] + abc[1] == abc[2]) plus = true;
            if (abc[0] - abc[1] == abc[2]) minus = true;
            if (plus && minus) Console.WriteLine("?");
            else if (plus) Console.WriteLine("+");
            else if (minus) Console.WriteLine("-");
            else Console.WriteLine("!");
        }
    }
}