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
            console.ReadLine();
            var p = console.ReadLine().Split().Select(i=>int.Parse(i));
            int t = 0;
            console.WriteLine(p.Skip(1).Zip(p,(a,b)=>a==b).Select(i=>{if(i) t++; else t=0;return t;}).Count(i=>i%2==1));
            
        }
    }
}