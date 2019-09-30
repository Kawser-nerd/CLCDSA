using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC002B
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime ymd = DateTime.Parse(Console.ReadLine());
            
            while(true)
            {
                int year = ymd.Year;
                int month = ymd.Month;
                int day = ymd.Day;

                if (year % month == 0 && (year / month) % day == 0)
                    break;

                ymd = ymd.AddDays(1.0);
            }

            Console.WriteLine("{0:0000}/{1:00}/{2:00}", ymd.Year, ymd.Month, ymd.Day);
        }
    }
}