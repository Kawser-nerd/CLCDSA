using System;
using System.Collections.Generic;
using System.Linq;


namespace TestApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var lists = Console.ReadLine()
                .ToArray();
            var count = lists.Length;
            var unkos = new List<string>();
            unkos.Add(lists[0].ToString());
            long ans = 0;
            for (long i = 1; i < count; i++)
            {
                unkos = Unkoman(unkos, long.Parse(lists[i].ToString()));
            }
            foreach (var item in unkos)
            {
                long num = 0;
                var i = item.Split(new[] { '+' }, StringSplitOptions.RemoveEmptyEntries);
                foreach (var item2 in i)
                {
                    num += long.Parse(item2);
                }
                ans += num;
            }
            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static List<string> Unkoman(List<string> vs, long unko)
        {
            var ls = new List<string>();
            foreach (var item in vs)
            {
                ls.Add(item + "+" + unko);
                ls.Add(item +  unko);
            }
            return ls;
        }
    }
    
}