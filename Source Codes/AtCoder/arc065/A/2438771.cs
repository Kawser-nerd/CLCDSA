using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.VisualBasic;

namespace ARC65_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var c = Console.ReadLine().ToCharArray();
            Array.Reverse(c);
            string s = new String(c);
            while (s.Length != 0)
            {
                string x = s.Substring(0, 5);
                if (x == "maerd") s = s.Substring(5);
                else if (x == "esare") s = s.Substring(5);
                else if (x + s[5] == "resare") s = s.Substring(6);
                else if (x + s[5] + s[6] == "remaerd") s = s.Substring(7);
                else break;
            }

            Console.WriteLine(s.Length == 0 ? "YES" : "NO");
        }
    }
}