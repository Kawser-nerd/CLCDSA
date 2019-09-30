using System;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var ymd = Array.ConvertAll( Console.ReadLine().Split('/'), s => int.Parse(s) );
            int y = ymd[0];
            int m = ymd[1];
            int d = ymd[2];

            while(true)
            {
                if( y%m == 0 && (y/m)%d == 0 )
                {
                    break;
                }
                AddDay( ref y, ref m, ref d, CalcDayMax(y, m) );
            }
            Console.WriteLine( string.Format("{0}/{1:D2}/{2:D2}", y, m, d) );
        }

        private static bool AddMonth( ref int y, ref int m, ref int d )
        {
            bool ret = false;
            if(++m>12)
            {
                m = 1;
                d = 1;
                ++y;
                ret = true;
            }
            return ret;
        }

        private static bool AddDay( ref int y, ref int m, ref int d, int dayMax )
        {
            bool ret = false;
            if(++d>dayMax)
            {
                d = 1;
                AddMonth( ref y, ref m, ref d );
                ret = true;
            }
            return ret;
        }

        private static int CalcDayMax(int y, int m)
        {
            switch(m)
            {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    return 31;

                case 4:
                case 6:
                case 9:
                case 11:
                    return 30;

                case 2:
                    if( IsUru(y) )
                    {
                        return 29;
                    }
                    else
                    {
                        return 28;
                    }
            }

            return 30;
        }

        private static bool IsUru( int y )
        {
            if(y%400==0) return true;
            if(y%100==0) return false;
            if(y%4==0) return true;
            return false;
        }
    }
}