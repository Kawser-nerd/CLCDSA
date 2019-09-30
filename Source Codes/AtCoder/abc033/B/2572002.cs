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
            int hoge = int.Parse(Console.ReadLine());
            
            string[] moge = new string[hoge];
            int[] foo = new int[hoge];

            int sum = 0;

            for(int i= 0; i < hoge; ++i)
            {
                string[] piyo = piyo = Console.ReadLine().Split(' ').ToArray();
                moge[i] = piyo[0];
                foo[i] = int.Parse(piyo[1]);
                sum += int.Parse(piyo[1]);
            }

            for (int j = 0; j < hoge; j++)
            {
                if (foo[j] > sum / 2)
                {
                    Console.WriteLine(moge[j]);
                    return;
                }
            }
                          
            Console.WriteLine("atcoder");
            Console.Read();
        }      
    }
}