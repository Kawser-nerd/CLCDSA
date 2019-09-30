using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            int iN = int.Parse(Console.ReadLine().Trim());

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOK = 2025;
            int iDf = iOK - iN;
            List<string> sOut = new List<string>();
            switch (iDf)
            {
                case 01:
                    sOut.Add("1 x 1");
                    break;
                case 02:
                    sOut.Add("1 x 2");
                    sOut.Add("2 x 1");
                    break;
                case 03:
                    sOut.Add("1 x 3");
                    sOut.Add("3 x 1");
                    break;
                case 04:
                    sOut.Add("1 x 4");
                    sOut.Add("2 x 2");
                    sOut.Add("4 x 1");
                    break;
                case 05:
                    sOut.Add("1 x 5");
                    sOut.Add("5 x 1");
                    break;
                case 06:
                    sOut.Add("1 x 6");
                    sOut.Add("2 x 3");
                    sOut.Add("3 x 2");
                    sOut.Add("6 x 1");
                    break;
                case 07:
                    sOut.Add("1 x 7");
                    sOut.Add("7 x 1");
                    break;
                case 08:
                    sOut.Add("1 x 8");
                    sOut.Add("2 x 4");
                    sOut.Add("4 x 2");
                    sOut.Add("8 x 1");
                    break;
                case 09:
                    sOut.Add("1 x 9");
                    sOut.Add("3 x 3");
                    sOut.Add("9 x 1");
                    break;
                case 10:
                    sOut.Add("2 x 5");
                    sOut.Add("5 x 2");
                    break;
                case 12:
                    sOut.Add("2 x 6");
                    sOut.Add("3 x 4");
                    sOut.Add("4 x 3");
                    sOut.Add("6 x 2");
                    break;
                case 14:
                    sOut.Add("2 x 7");
                    sOut.Add("7 x 2");
                    break;
                case 15:
                    sOut.Add("3 x 5");
                    sOut.Add("5 x 3");
                    break;
                case 16:
                    sOut.Add("2 x 8");
                    sOut.Add("4 x 4");
                    sOut.Add("8 x 2");
                    break;
                case 18:
                    sOut.Add("2 x 9");
                    sOut.Add("3 x 6");
                    sOut.Add("6 x 3");
                    sOut.Add("9 x 2");
                    break;
                case 20:
                    sOut.Add("4 x 5");
                    sOut.Add("5 x 4");
                    break;
                case 21:
                    sOut.Add("3 x 7");
                    sOut.Add("7 x 3");
                    break;
                case 24:
                    sOut.Add("3 x 8");
                    sOut.Add("4 x 6");
                    sOut.Add("6 x 4");
                    sOut.Add("8 x 3");
                    break;
                case 25:
                    sOut.Add("5 x 5");
                    break;
                case 27:
                    sOut.Add("3 x 9");
                    sOut.Add("9 x 3");
                    break;
                case 28:
                    sOut.Add("4 x 7");
                    sOut.Add("7 x 4");
                    break;
                case 30:
                    sOut.Add("5 x 6");
                    sOut.Add("6 x 5");
                    break;
                case 32:
                    sOut.Add("4 x 8");
                    sOut.Add("8 x 4");
                    break;
                case 35:
                    sOut.Add("5 x 7");
                    sOut.Add("7 x 5");
                    break;
                case 36:
                    sOut.Add("4 x 9");
                    sOut.Add("6 x 6");
                    sOut.Add("9 x 4");
                    break;
                case 40:
                    sOut.Add("5 x 8");
                    sOut.Add("8 x 5");
                    break;
                case 42:
                    sOut.Add("6 x 7");
                    sOut.Add("7 x 6");
                    break;
                case 45:
                    sOut.Add("5 x 9");
                    sOut.Add("9 x 5");
                    break;
                case 48:
                    sOut.Add("6 x 8");
                    sOut.Add("8 x 6");
                    break;
                case 49:
                    sOut.Add("7 x 7");
                    break;
                case 54:
                    sOut.Add("6 x 9");
                    sOut.Add("9 x 6");
                    break;
                case 56:
                    sOut.Add("7 x 8");
                    sOut.Add("8 x 7");
                    break;
                case 63:
                    sOut.Add("7 x 9");
                    sOut.Add("9 x 7");
                    break;
                case 64:
                    sOut.Add("8 x 8");
                    break;
                case 72:
                    sOut.Add("8 x 9");
                    sOut.Add("9 x 8");
                    break;
                case 81:
                    sOut.Add("9 x 9");
                    break;
            }

            //??
            for (int i = 0; i < sOut.Count; i++)
            {
                Console.WriteLine("{0}", sOut[i].ToString());
            }

            sw.Stop();
#if DEBUG
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}