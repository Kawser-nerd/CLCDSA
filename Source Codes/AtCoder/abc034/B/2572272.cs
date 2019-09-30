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

            if(hoge %2 == 0)
            {
                Console.WriteLine(hoge - 1);
            }
            else
            {
                Console.WriteLine(hoge + 1);
            }

            Console.Read();
        }      
    }
}