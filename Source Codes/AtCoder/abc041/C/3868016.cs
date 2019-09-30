using System;
using System.Linq;
using System.Collections.Generic;

namespace ABC041_C{
    class Program{
        static void Main(string[] args){
            var n = long.Parse(Console.ReadLine());
            var res = Console.ReadLine().Split(' ').Select((s,i) => new KeyValuePair<int,int>(i + 1,int.Parse(s))).OrderByDescending(p => p.Value);
            foreach(var r in res)Console.WriteLine(r.Key);
        }
    }
}