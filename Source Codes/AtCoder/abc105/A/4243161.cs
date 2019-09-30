using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace template
{
    class Program
    {
        static void Main(string[] args)
        {
            var imp = Console.ReadLine().Split(' ');

            int N = int.Parse(imp[0]);
            int K = int.Parse(imp[1]);
            int a = 0;

            a = (N % K == 0) ? 0:1;
            Console.WriteLine(a);


           






           // System.Threading.Thread.Sleep(1000);    //for debug

        }
    }
}