using System;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            var w = Console.ReadLine().ToCharArray();
            var result = string.Empty;

            foreach(var item in w)
            {
                if(result.Contains(item))
                {
                    result = result.Replace(item.ToString(), "");
                    continue;
                }
                result += item;
            }
            
            if(result.Any())
            {
                Console.WriteLine("No");
                return;
            }
            Console.WriteLine("Yes");
        }
    }
}