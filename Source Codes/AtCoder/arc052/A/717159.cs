using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace ConsoleApplication15
{
    class Program
    {
        static void Main(string[] args)
        {
            string S = Console.ReadLine();
            string ans = Regex.Replace(S, "[a-zA-Z]", "");
            Console.WriteLine(ans);
        }
    }
}