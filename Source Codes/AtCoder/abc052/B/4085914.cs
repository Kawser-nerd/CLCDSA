using System;
using System.Collections.Generic;
using System.Linq;
 
namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            var x = 0;
            var N = int.Parse(Console.ReadLine());
            var s = Console.ReadLine();
            var a = new List<int>(){0};

            for (int i = 0; i < N; i++)
            {
                if((s[i]).ToString() == "I") a.Add(x = x + 1);
                if((s[i]).ToString() == "D") a.Add(x = x - 1);
            }
            Console.WriteLine(a.Max());
        }        
    }
}