using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using static Exter;
using console=System.Console;
namespace AtCoderTemplate
{
    public class App
    {
        public static void Main()
        {
var p = console.ReadLine().Split().Select(s=>short.Parse(s));
console.WriteLine(Max(p.Sum(v=>v),p.First()-p.Last(),p.First()*p.Last()));

        }
    }
}
public static class Exter
{
    public static int Max(params int[] p)=>p.Max();
    public static short Max(params short[] p)=>p.Max();
    public static long Max(params long[] p)=>p.Max();
}