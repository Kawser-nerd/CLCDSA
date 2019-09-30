using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace abc_060_C
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            long ans = 0;
            for(int i = 0; i < n[0]-1; i++)
            {
                while (true)
                {
                    if (i >= n[0] - 1) { break; }
                    if (a[i] + n[1] > a[1+i]) { ans += a[i+1]-a[i]; }
                    else { ans += n[1]; break; }
                    i++;
                }
            }
            Console.WriteLine(ans+n[1]);
            Console.ReadLine(); }
    }
}