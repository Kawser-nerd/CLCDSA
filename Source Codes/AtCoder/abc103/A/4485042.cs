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

            var imp = Console.ReadLine().Split(' ');
            int[] data = new int[3];

            for(int i =0;i<3;++i)
            {
                data[i] = int.Parse(imp[i]);
            }

            Array.Sort(data);

            Console.Write(((data[1]) - (data[0])) + ((data[2]) - (data[1])));


            //System.Threading.Thread.Sleep(1000);
        }
    }
}