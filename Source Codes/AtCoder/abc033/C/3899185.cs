using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC033_C{
    class Program{
        static void Main(string[] args){
            var s = Console.ReadLine().Split('+').ToList();
            var ans = s.Count(x => !(x.Contains('0')));
            Console.WriteLine(ans);
        }
    }
}