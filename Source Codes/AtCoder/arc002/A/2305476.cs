namespace AtCoderTestApp
{
    using System;
    using System.Collections.Generic;
    using System.IO;

    /// <summary>
    /// ??????
    /// </summary>
    public class ProblemUruu
    {
        [STAThread]
        static void Main()
        {
            Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });

            string line;
            while ((line = Console.ReadLine()) != null)
            {
                int intValue;
                var inputText = line;

                int.TryParse(inputText, out intValue);
                var calcResult = IsLeapYear(intValue);
                if (calcResult)
                {
                    Console.WriteLine("YES");
                }
                else
                {
                    Console.WriteLine("NO");
                }
            }

            Console.Out.Flush();
        }

        /// <summary>
        /// ??????
        /// </summary>
        /// <param name="year">?</param>
        /// <returns>true:???? false:??</returns>
        private static bool IsLeapYear(int year)
        {
            int amari4 = year % 4;
            if (amari4 == 0)
            {
                int amari100 = year % 100;
                if (amari100 == 0)
                {
                    int amari400 = year % 400;
                    if (amari400 == 0)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
}