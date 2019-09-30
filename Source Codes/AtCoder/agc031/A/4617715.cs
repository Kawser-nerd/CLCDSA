using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using static System.Console;

namespace Code_test
{
    class Program
    {
        static void Main(string[] args) {
            ReadLine();
            string ABC = "abcdefghijklmnopqrstuvwxyz";
            var list = new List<char>(ReadLine().ToCharArray()).ToList();
            Dictionary<char, int> Dict = new Dictionary<char, int>();
            foreach (char e in ABC) Dict.Add(e, 0);
            foreach (char e in list) Dict[e]++;
            Decimal Result = 1;
            foreach (var e in Dict) {
                Result *= e.Value + 1;
                Result %= (Decimal)Math.Pow(10, 9) + 7;
            }
            WriteLine((Result - 1));

            ReadLine();
        }
    }
}