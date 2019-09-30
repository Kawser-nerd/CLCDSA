using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace abc119d
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length > 0)
            {
                Console.SetIn(new StreamReader(args[0]));
            }

            new Program().Solve();
        }

        void Solve()
        {
            var temp = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            var a = temp[0];
            var b = temp[1];
            var q = temp[2];
            var s = new long[a];
            var t = new long[b];
            var x = new long[q];

            for (int i = 0; i < a; i++)
            {
                s[i] = long.Parse(Console.ReadLine());
            }

            for (int i = 0; i < b; i++)
            {
                t[i] = long.Parse(Console.ReadLine());
            }

            Console.Error.WriteLine("A:" + string.Join(",", s));
            Console.Error.WriteLine("B:" + string.Join(",", t));

            for (int i = 1; i <= q; i++)
            {
                var start = long.Parse(Console.ReadLine());
                Console.Error.WriteLine("Q" + i + ":" + start);
                var distanceList = new List<long>();

                // distanceList.Add(GetDistance(s, t, start, 0, 0));
                // distanceList.Add(GetDistance(s, t, start, 0, 1));
                // distanceList.Add(GetDistance(s, t, start, 1, 0));
                // distanceList.Add(GetDistance(s, t, start, 1, 1));
                // distanceList.Add(GetDistance(t, s, start, 0, 0));
                // distanceList.Add(GetDistance(t, s, start, 0, 1));
                // distanceList.Add(GetDistance(t, s, start, 1, 0));
                // distanceList.Add(GetDistance(t, s, start, 1, 1));

                // distanceList.Add(GetDistance2(s, t, start, 0));
                // distanceList.Add(GetDistance2(s, t, start, 1));
                // distanceList.Add(GetDistance2(t, s, start, 0));
                // distanceList.Add(GetDistance2(t, s, start, 1));

                distanceList.Add(GetDistance3(s, t, start));
                distanceList.Add(GetDistance3(t, s, start));

                Console.WriteLine(distanceList.Min());
            }
        }

        // array1: ??????????????
        // array2: ?????????????
        // start: ????
        // direction1: ????????(0:??1:?)
        // direction2: ???????(0:??1:?)
        long GetDistance(long[] array1, long[] array2, long start, int direction1, int direction2)
        {
            var distance = long.MaxValue;
            var index1 = GetIndex(array1, start) + direction1;

            if (0 <= index1 && index1 < array1.Length)
            {
                distance = Math.Abs(array1[index1] - start);
                var index2 = GetIndex(array2, array1[index1]) + direction2;

                if (0 <= index2 && index2 < array2.Length)
                {
                    distance += Math.Abs(array2[index2] - array1[index1]);
                }
                else
                {
                    distance = long.MaxValue;
                }
            }
            else
            {
                distance = long.MaxValue;
            }

            // Console.Error.WriteLine("distance:" + distance);
            return distance;
        }

        // direction1??????????????????
        long GetDistance2(long[] array1, long[] array2, long start, int direction1)
        {
            var distance1 = long.MaxValue;
            var distance20 = long.MaxValue;
            var distance21 = long.MaxValue;
            var index1 = GetIndex(array1, start) + direction1;

            if (0 <= index1 && index1 < array1.Length)
            {
                distance1 = Math.Abs(array1[index1] - start);
                var index2 = GetIndex(array2, array1[index1]);

                if (0 <= index2)
                {

                    distance20 = Math.Abs(array2[index2] - array1[index1]);
                }

                if (index2 < array2.Length - 1)
                {
                    distance21 = Math.Abs(array2[index2 + 1] - array1[index1]);
                }
            }
            else
            {
                return long.MaxValue;
            }

            return distance1 + Math.Min(distance20, distance21);
        }

        long GetDistance3(long[] array1, long[] array2, long start)
        {
            var distance00 = long.MaxValue; // ???
            var distance01 = long.MaxValue; // ???
            var distance10 = long.MaxValue; // ???
            var distance11 = long.MaxValue; // ???
            var index1 = GetIndex(array1, start);

            if (0 <= index1)
            {
                // ?
                distance00 = Math.Abs(array1[index1] - start);
                distance01 = distance00;
                var index2 = GetIndex(array2, array1[index1]);

                if (0 <= index2)
                {
                    // ???
                    distance00 += Math.Abs(array2[index2] - array1[index1]);
                }
                else
                {
                    distance00 = long.MaxValue;
                }

                if (index2 < array2.Length - 1)
                {
                    // ???
                    distance01 += Math.Abs(array2[index2 + 1] - array1[index1]);
                }
                else
                {
                    distance01 = long.MaxValue;
                }
            }

            if (index1 < array1.Length - 1)
            {
                // ?
                distance10 = Math.Abs(array1[index1 + 1] - start);
                distance11 = distance10;
                var index2 = GetIndex(array2, array1[index1 + 1]);

                if (0 <= index2)
                {
                    // ???
                    distance10 += Math.Abs(array2[index2] - array1[index1 + 1]);
                }
                else
                {
                    distance10 = long.MaxValue;
                }

                if (index2 < array2.Length - 1)
                {
                    // ???
                    distance11 += Math.Abs(array2[index2 + 1] - array1[index1 + 1]);
                }
                else
                {
                    distance11 = long.MaxValue;
                }
            }

            return new List<long>{ distance00, distance01, distance10, distance11 }.Min();
        }

        // array[index] <= value < array[index + 1]???index???
        int GetIndex(long[] array, long value)
        {
            var min = -1;
            var max = array.Length - 1;
            var index = (max - min) / 2 + min;

            while (true)
            {
                if (index == -1 || index == array.Length - 1)
                {
                    break;
                }

                // Console.Error.WriteLine("min:" + min + ",max:" + max + ",index:" + index + ",value:" + array[index]);

                if (value < array[index])
                {
                    max = index;
                }
                else if (array[index + 1] <= value)
                {
                    min = index + 1;
                }
                else
                {
                    break;
                }

                index = (max - min) / 2 + min;
            }

            return index;
        }
    }
}