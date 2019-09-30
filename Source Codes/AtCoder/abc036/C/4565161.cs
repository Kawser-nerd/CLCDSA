using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]C - ??
            
            int n = int.Parse(Console.ReadLine());
            
            //????????
            var pressures = GetSeatPressures(n).ToList();
            
            //????????????????????
            var distinct = pressures.Distinct().OrderBy(x => x).ToList();
            
            //?????????
            var orders = GetOrders(distinct);
            
            foreach(var p in pressures)
            {
               Console.WriteLine(orders[p]);    
            }
        }
        
        static Dictionary<int, int> GetOrders(List<int> pressures)
        {
            var dic = new Dictionary<int, int>();
            int i = 0;
            
            foreach(var p in pressures)
            {
                dic.Add(p, i);
                i++;
            }
            
            return dic;
        }
        
        static IEnumerable<int> GetSeatPressures(int n)
        {
            for(int i = 0;i <n; i++)
            {
                string s = Console.ReadLine();
                yield return int.Parse(s);
            }   
        }
    }
}