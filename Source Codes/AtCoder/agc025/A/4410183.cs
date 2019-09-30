using System;
using System.Collections.Generic;
using System.Linq;
//????????????????????? used to be O(N log N)??easy
namespace AtCoderTemplate
{
    public class App
    {
        public static void Main(string[] args)
        {
            var k = int.Parse(Console.ReadLine()); Console.WriteLine(Enumerable.Range(1,k/2).Select(v=>new {p=v,q=k-v}).Select(v=>v.p.ToString().ToCharArray().Sum(c=>c-'0')+v.q.ToString().ToCharArray().Sum(c=>c-'0')).Min());
        }
    }
}