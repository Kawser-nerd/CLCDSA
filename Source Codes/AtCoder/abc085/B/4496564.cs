using System;
using System.Collections.Generic;
using System.Linq;

namespace atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            var d_list = new List<int>();
            for(int i=0;i<N;i++){
                d_list.Add(int.Parse(Console.ReadLine()));
            }
            //sort
            d_list.Sort();
            int num = 1;
            for(int i=1;i<N;i++){
                if(d_list[i]>d_list[i-1]) num++;
            }
            Console.WriteLine(num);
        }
    }
}