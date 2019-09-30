using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            var giftList = new List<Gift>();

            for(int k = 1; k <= N; k++)
            {
                string[] input = Console.ReadLine().Split(' ');
                giftList.Add(new Gift(double.Parse(input[0]), input[1]));
            }

            double s = 0;

            foreach(var gift in giftList)
            {
                s += gift.ToYen();
            }

            Console.WriteLine(s);

        }
    }

    class Gift
    {
        public double mount;
        public string unit;

        public Gift(double mount, string unit)
        {
            this.mount = mount;
            this.unit = unit;
        }

        public double ToYen()
        {
            if(unit == "JPY")
            {
                return mount;
            }
            else
            {
                return mount * 380000;
            }
        }


    }
}