using System;
using System.Collections.Generic;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = KyoproLibrary.ReadInteger();
            int[,] points = KyoproLibrary.ReadIntegerPairArray(n);
            double max_distance = 0;
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    double distance = DistSqrd(points[i, 0], points[i, 1], points[j, 0], points[j, 1]);
                    if (distance > max_distance) max_distance = distance;
                }
            }
            Console.WriteLine(Math.Sqrt(max_distance));
            Console.ReadLine();
        }

        static double DistSqrd(int x, int y, int _x, int _y)
        {
            return KyoproLibrary.FastPower(x - _x, 2) + KyoproLibrary.FastPower(y - _y ,2);
        }
    }

    class KyoproLibrary
    {
        static public int[] ReadIntegerArray()
        {
            string[] tmp = Console.ReadLine().Split(' ');
            int[] result = new int[tmp.Length];
            for (int i = 0; i < tmp.Length; i++) {
                result[i] = int.Parse(tmp[i]);
            }
            return result;
        }

        static public int ReadInteger()
        {
            return int.Parse(Console.ReadLine());
        }

        static public int[,] ReadIntegerPairArray(int n)
        {
            int[,] returnvalues = new int[n, 2];
            for (int i = 0; i < n; i++) {
                string[] pair_str = Console.ReadLine().Split(' ');
                returnvalues[i, 0] = int.Parse(pair_str[0]);
                returnvalues[i, 1] = int.Parse(pair_str[1]);
            }
            return returnvalues;
        }

        public static int FastPower(int _base, int exponent)
        {
            if (exponent == 0) return 1;
            else if (exponent == 1) return _base;
            else if (exponent % 2 == 0) {
                int tmp = FastPower(_base, exponent / 2);
                return tmp * tmp;
            } else {
                int tmp = FastPower(_base, (exponent - 1) / 2);
                return tmp * tmp * _base;
            }
        }
    }
}