using System;
using System.Linq;
    class Program
    {
      	static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine().Split(' ').First());
            var ds = Console.ReadLine().Split(' ').ToList();
            for(var i =N; ;i++)
            {
                var stri = i.ToString();
                if(ds.All(d => !stri.Contains(d)))
                {
                    Console.WriteLine(i);
                    return;
                }
            }
        }
    }