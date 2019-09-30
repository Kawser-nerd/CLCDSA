using System;
using System.Collections.Generic;
using System.Linq;
using static System.Math;
using System.Security.Cryptography;
using console=System.Console;
namespace AtCoderTemplate
{
    public class App
    {
        public static void Main()
        {
var p = console.ReadLine().ToCharArray().Select(c=>c-'0').Select((v,i)=>new {v,i});
if(p.All(c=>c.v==1)||p.First(c=>c.v!=1).i>long.Parse(console.ReadLine())-1)
console.WriteLine(1);
else
console.WriteLine(p.First(c=>c.v!=1).v);

        }
    }
}