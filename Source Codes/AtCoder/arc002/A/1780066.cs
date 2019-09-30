using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ForArRecoder
{
    class Program
    {
        static void Main(string[] args)
        {
            bool isUruu = IsUruu();
            if (isUruu)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }

        }
        private static bool IsUruu()
        {
            string input = Console.ReadLine();
            int year = int.Parse(input);
            int modYear = year % 4;
            if (modYear == 0)
            {
                if(year % 400 == 0)
                {
                    return true;
                }
                if (year % 100 == 0)
                {
                    return false;
                }
                return true;
            }
            return false;
        }
    }
}