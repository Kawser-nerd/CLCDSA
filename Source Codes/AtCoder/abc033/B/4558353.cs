using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] citiespop= new int[N];
            string[] citynames = new string[N];

            string ans = null;

            for (int i = 0; N > i; ++i) 
            {
                var imp = Console.ReadLine().Split(' ');
                
                citiespop[i] = int.Parse(imp[1]);
                citynames[i] = imp[0];

            }
            int maxpop = citiespop.Max();
            int maxcitynum = Array.IndexOf(citiespop, maxpop);
            //Console.Write(maxcitynum);

            //Console.Write(citynames[maxcitynum]);

            if (maxpop > (citiespop.Sum() / 2))
            {
                Console.WriteLine(citynames[maxcitynum]);
            }
            else
            {
                Console.WriteLine("atcoder");
            }
          
            
            
           

            

          // System.Threading.Thread.Sleep(1000);
        }
    }
}