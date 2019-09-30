using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SoloLearn
{
    class Program
    {
        static void Main(string[] args)
        {
            string inp = Console.ReadLine();
            
            for(int i = 0;i<3;i++)
            {
              char num = inp[i];
                 
                if(num=='1')
                {
                    num='9';
                }
                else
                {
                    num='1';
                }
                
             Console.Write(num);
            }
            
        }
    }
}