using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int q = int.Parse(input[1]);

            int[] list = new int[n];

            for(int i =0; i<q;i++)
            {
                string[] edit = Console.ReadLine().Split(' ');
                int start = int.Parse(edit[0])- 1 ;
                int end = int.Parse(edit[1]);
                int number = int.Parse(edit[2]);

                for(int j = start; j < end; j++)
                {
                    list[j] = number;  
                }
            }

            foreach(int temp in list)
            {
                Console.WriteLine(temp);
            }
            
        }
    }
}