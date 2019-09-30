using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace GoogleCodeJam
{
    class Program
    {
        private static bool[] bNA;
        private static bool[] bNB;
        private static int T, NA, NB;
        private static int[] naBegin;
        private static int[] naEnd;
        private static int[] nbBegin;
        private static int[] nbEnd;

        private static void go(int index, int flag)
        {
            if(flag == 0)
            {
                bNA[index] = true;
                int endTime = naEnd[index] + T;
                for(int i = 0; i < NB; i++)
                    if(!bNB[i] && nbBegin[i] >= endTime)
                    {
                        go(i, 1);
                        break;
                    }
            }
            else
            {
                bNB[index] = true;
                int endTime = nbEnd[index] + T;
                for(int i = 0; i < NA; i++)
                    if(!bNA[i] && naBegin[i] >= endTime)
                    {
                        go(i, 0);
                        break;
                    }
            }
        }

        static void Main(string[] args)
        {
            var sr = new StreamReader("input.txt");
            var sw = new StreamWriter("output.txt");
            var N = int.Parse(sr.ReadLine());

            for (var i = 0; i < N; i++)
            {
                T = int.Parse(sr.ReadLine());
                var temp = sr.ReadLine().Split(' ');

                NA = int.Parse(temp[0]);
                NB = int.Parse(temp[1]);

                naBegin = new int[NA];
                naEnd = new int[NA];
                nbBegin = new int[NB];
                nbEnd = new int[NB];

                for(var j = 0; j < NA; j++)
                {
                    temp = sr.ReadLine().Split(' ');
                    var ntemp = temp[0].Split(':');
                    naBegin[j] = int.Parse(ntemp[0])*60 + int.Parse((ntemp[1]));

                    ntemp = temp[1].Split(':');
                    naEnd[j] = int.Parse(ntemp[0]) * 60 + int.Parse((ntemp[1]));
                }

                for (var j = 0; j < NB; j++)
                {
                    temp = sr.ReadLine().Split(' ');
                    var ntemp = temp[0].Split(':');
                    nbBegin[j] = int.Parse(ntemp[0]) * 60 + int.Parse((ntemp[1]));

                    ntemp = temp[1].Split(':');
                    nbEnd[j] = int.Parse(ntemp[0]) * 60 + int.Parse((ntemp[1]));
                }

                Array.Sort(naBegin, naEnd);
                Array.Sort(nbBegin, nbEnd);

                bNA = new bool[NA];
                bNB = new bool[NB];
                int result1 = 0;
                int result2 = 0;
                int ind1 = 0;
                int ind2 = 0;
                while(ind1 < NA && ind2 < NB)
                {
                    if (bNA[ind1]) { ind1++; }
                    else if (bNB[ind2]) { ind2++; }
                    else 
                    {
                        if(naBegin[ind1] < nbBegin[ind2])
                        {
                            go(ind1, 0);
                            ind1++;
                            result1++;
                        }
                        else
                        {
                            go(ind2, 1);
                            ind2++;
                            result2++;
                        }
                    }
                }

                for (int j = 0; j < NA; j++)
                    if (!bNA[j])
                        result1++;

                for (int j = 0; j < NB; j++)
                    if (!bNB[j])
                        result2++;

                sw.WriteLine("Case #" + (i + 1) + ": " + result1 + " " + result2);
            }

            sw.Close();
        }
    }
}
