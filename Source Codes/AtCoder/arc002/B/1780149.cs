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
            Console.WriteLine( Result());
            Console.Read();

        }
        private static bool IsUruu(double checkYear)
        {
            int year = (int)checkYear;
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

        private static string Result()
        {
            string[] input = Console.ReadLine().Split('/');
            double year  = int.Parse(input[0].ToString());
            double month = int.Parse(input[1].ToString());
            double day   = int.Parse(input[2].ToString());
            while (true)
            {
                double check = year / month / day;
                double afterFloor = Math.Floor(year / month / day);
                if(check == afterFloor)
                {
                    string result = year + "/" + month.ToString("00") + "/" + day.ToString("00");
                    return result;
                }
                if(month == 2)
                {
                    bool isUruu = IsUruu(year);
                    if (isUruu)
                    {
                        if(day < 29)
                        {
                            day++;
                            continue;
                        }
                    }else
                    {
                        if(day < 28)
                        {
                            day++;
                            continue;
                        }
                    }
                    AddMonthAndYear(ref year, ref month, ref day);
                    continue;
                }
                if(month == 4 || month == 6 || month == 9 || month == 11)
                {
                    if(day < 30)
                    {
                        day++;
                        continue;
                    }
                    AddMonthAndYear(ref year, ref month, ref day);
                    continue;
                }
                if(day < 31)
                {
                    day++;
                    continue;
                }
                AddMonthAndYear(ref year, ref month, ref day);
                continue;
            }
            return "not find";
        }

        private static void AddMonthAndYear(ref double year, ref double month, ref double day)
        {
            day = 1;
            if(month == 12)
            {
                month = 1;
                year++;
                return;
            }
            month++;

        }
    }
}