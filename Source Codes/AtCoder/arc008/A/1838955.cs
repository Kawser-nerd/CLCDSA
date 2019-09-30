using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ForRecords
{
    class Program
    {
        static void Main(string[] args)
        {
            Practice practice = new Practice();
                Console.WriteLine(practice.GetMoney());
                
            Console.ReadLine();
        }
        
    }

    class Practice
    {
        private int num;
        private int money;
        public Practice()
        {
            num = int.Parse(Console.ReadLine());
        }

        public int GetMoney()
        {
            int valuePack = num / 10;
            int one = num % 10;
            if(one > 6)
            {
                valuePack++;
                one = 0;
            }
            money = (valuePack * 100) + (one * 15);
            return money;

        }
    }
}