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
            var p = long.Parse(console.ReadLine().Split()[1]);
          console.WriteLine(console.ReadLine().Split().Select(i=>long.Parse(i)).OrderBy(i=>i).Select(i=>{p-=i;return p;}).Count(i=>i>=0)-(p>0?1:0));
        }
    }
}