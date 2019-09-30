namespace AtCoderTestApp
{
    using System;
    using System.Collections.Generic;
    using System.IO;

    /// <summary>
    /// ??????
    /// </summary>
    public class ProblemTakoyaki
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
                var calcResult = CalcKingaku(intValue);
                Console.WriteLine(calcResult.ToString());
            }

            Console.Out.Flush();
        }

        /// <summary>
        /// ??????
        /// </summary>
        /// <param name="kosu">??????</param>
        /// <returns>????</returns>
        private static int CalcKingaku(int kosu)
        {
            int pack = kosu / 10;
            int amari = kosu % 10;

            if (amari == 0)
            {
                return pack * 100;
            }
            else
            {
                int hasu = amari * 15;
                if (hasu < 100)
                {
                    return pack * 100 + hasu;

                }
                else
                {
                    return pack * 100 + 100;
                }
            }
        }
    }
}