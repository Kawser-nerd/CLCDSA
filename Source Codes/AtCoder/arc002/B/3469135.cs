using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1????
            string input = Console.ReadLine();

            // ??????
            DateTime dt = DateTime.Parse(input);

            // ????????
            int year, month, day;

            // ????????????????
            while (true)
            {
                // ????????
                year = dt.Year;
                month = dt.Month;
                day = dt.Day;

                // ??????????
                if(year % month == 0 && (year / month) % day == 0)
                {
                    break;
                }

                // 1?????
                dt = dt.AddDays(1);
            }

            // ???????
            Console.WriteLine(dt.Year + "/" + dt.Month.ToString("00") + "/" + dt.Day.ToString("00"));
        }
    }
}