using System;

namespace ARC002B
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string ss = Console.ReadLine();

            DateTime dt = DateTime.Parse(ss);
            while(dt.Year % (dt.Month * dt.Day) != 0)
            {
                dt = dt.AddDays(1);
            }

            //??
            Console.WriteLine(dt.ToString("yyyy/MM/dd"));
        }
    }
}