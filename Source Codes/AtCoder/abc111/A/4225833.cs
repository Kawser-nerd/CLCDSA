using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Main
{
    class Program
    {
        static void Main(string[] arg)
        {
            var line = Console.ReadLine().ToCharArray();
            string answer = "";
            foreach (char c in line)
            {
                string str = c == '1' ? "9" : "1";
                answer += str;
            }

            Console.WriteLine(answer);
            Console.ReadLine();

        }
    }
}