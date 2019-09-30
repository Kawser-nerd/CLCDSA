using System;
using System.Collections.Generic;
using System.Linq;
using console = System.Console;

namespace AtCoderTemplate
{
    public class App
    {
        public static void Main(string[] args)
        {
            var p = console.ReadLine().Split().Select(i=>int.Parse(i)).ToArray();
            console.WriteLine(Math.Min(p[0]+p[1]+1,p[2])+p[1]);
        }
    }
}