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
            int[] penk = new int[3];
            var imp = Console.ReadLine().Split(' ');
            penk[0] = int.Parse(imp[0]);
            penk[1] = int.Parse(imp[1]);
            penk[2] = int.Parse(imp[2]);

            Array.Sort(penk);
            if((penk[0]==penk[1])&&(penk[0]==penk[2]))
            {
                Console.Write('1');
                
            }
            else if((penk[0]==penk[1])&&(penk[1]<penk[2])||((penk[1] == penk[2]) && (penk[0] < penk[1])))
            {
                Console.Write('2');
            }
            else if(penk[0]<penk[1])
            {
                Console.Write('3');
            }
            else
            {

            }
           //System.Threading.Thread.Sleep(1000);
        }
    }
}