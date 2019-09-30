using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main() { Models.GetInstance.Run(); }
    }

    public class Models
    {
        static Models instance = new Models();
        private Models() { }

        public static Models GetInstance
            {get{return instance;} }

        public void Run()
        {
            int counter = 0;
            string[] input = Console.ReadLine().Split(' ');
            int k = int.Parse(input[0]);
            int s = int.Parse(input[1]);
            
            for (int i = 0; i <= k; i++)
            {

                for (int j = 0; j <= k; j++)
                {
                    if (i + j > s) continue;
                    if (s - i - j > k) continue;
                    counter++;

                }
            }
            Console.WriteLine(counter);
            ;


        }

    }
    
}