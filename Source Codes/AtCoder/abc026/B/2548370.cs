using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace _20180502_pra
{
    class Program
    {        
            static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());

            int sum = 0;

            List<int> b = new List<int>();

            for(int i = 0; i < a; ++i)
            {
                int c = int.Parse(Console.ReadLine());
                b.Add(c);
            }

            b.Sort((x, y) => y - x);

            for(int j = 0; j < b.Count; ++j)
            {
                if (j % 2 == 0)
                {
                   b[j]= b[j] * b[j];
                    sum += b[j];
                }
                else
                {
                    b[j] = -(b[j] * b[j]);
                    sum += b[j];
                }
            }

            double result = sum * Math.PI;

            Console.WriteLine(result);

            Console.Read();
        }      
    }
}