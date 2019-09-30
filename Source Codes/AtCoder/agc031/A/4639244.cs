using System;
using System.Linq;
namespace AtCoderTemplate
{
    public class App
    {
        public static void Main()=>Console.WriteLine("{1}",Console.ReadLine(),Console.ReadLine().ToCharArray().GroupBy(c=>c).Select(g=>g.Count()+1).Aggregate(1,(long i,int c)=>(i*c)%1000000007)-1);
    }
}