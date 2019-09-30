using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            
            bool include9 = false;
            string imp = Console.ReadLine();
            int L = imp.Length;
            for(int i =0; i<L;i++)
            { 
                switch(imp[i])
                {
                    case ('9'):
                        include9 = true;
                        break;
                    default:
                        
                        break;
                }
            }
            switch (include9)
            {
                case (true):
                    Console.Write("Yes");
                    break;
                default:
                    Console.Write("No");
                    break;
            }
            
            
            
            //System.Threading.Thread.Sleep(1000);
        }
    }
    
}