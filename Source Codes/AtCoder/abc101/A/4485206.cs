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

            int ans = 0;
            
            for(int i =0;i<4;++i)
            {
                var imp = Console.Read();

                if(imp=='+')
                {
                    ans += 1;
                }
                else
                {
                    ans -= 1;
                }


            }
            
            Console.Write(ans);
            
            //System.Threading.Thread.Sleep(1000);
        }
    }
}