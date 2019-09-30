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
var p = console.ReadLine().Split().Select(s=>long.Parse(s)).ToArray();
if(Abs(p[0]-p[1])>100000000000000000)
console.WriteLine("Unfair");
else if(p.Last()%2==0)
console.WriteLine(p[0]-p[1]);
else
console.WriteLine(p[1]-p[0]);
        }
    }/*
    public static class Extention
    {
        public static IEnumerable<TResult> AggregateOther<TSource,TAccumulate,TResult>(this IEnumerable<TSource> en,TAccumulate seed,Func<TAccumulate,TSource,TAccumulate> f,Func<TAccumulate,TResult> g)
        {
            if(en.Count()<2) throw new SystemException("Can't aggregate each other for 1-element-Enumerable");
            var p = en.Select((v,i)=>new{v,i}).ToArray();
            for(int i = 0;i<en.Count();i++)
            {
                
            }
        }
    }*/
}