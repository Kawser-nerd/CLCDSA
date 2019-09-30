using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace PS
{
    class Program
    {
        static void doSort(List<List<BigInteger>> tar)
        {
            for (int i = 0; i < tar.Count; i++)
            {
                for (int j = i + 1; j < tar.Count; j++)
                {
                    if (tar[i][0] > tar[j][0])
                    {
                        List<BigInteger> temp = tar[i];
                        tar[i] = tar[j];
                        tar[j] = temp;
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int caseN = 1; caseN <= T; caseN++)
            {
                string[] inp = Console.ReadLine().Split();
                BigInteger n = BigInteger.Parse(inp[0]);
                BigInteger m = BigInteger.Parse(inp[1]);

                Dictionary<BigInteger, BigInteger> end = new Dictionary<BigInteger, BigInteger>();
                List<List<BigInteger>> start = new List<List<BigInteger>>();
                List<BigInteger> endList = new List<BigInteger>();
                BigInteger orig = new BigInteger(0);

                for (int i = 0; BigInteger.Parse(i.ToString()) < m; i++)
                {
                    inp = Console.ReadLine().Split();
                    BigInteger curS = BigInteger.Parse(inp[0]);
                    BigInteger curE = BigInteger.Parse(inp[1]);
                    BigInteger curP = BigInteger.Parse(inp[2]);

                    List<BigInteger> curList = new List<BigInteger>();
                    curList.Add(curS);
                    curList.Add(curP);
                    start.Add(curList);

                    if (end.ContainsKey(curE) == false) end[curE] = new BigInteger(0);
                    end[curE] += curP;
                    endList.Add(curE);

                    BigInteger gap = curE - curS;
                    orig += (gap * n - gap * (gap - 1) / 2) * curP;
                }

                endList.Sort();
                List<List<BigInteger>> curWork = new List<List<BigInteger>>();
                BigInteger newAns = new BigInteger(0);                

                for (int i = 0; i < endList.Count; i++)
                {
                    if (i > 0 && endList[i] == endList[i - 1]) continue;
                    for (int j = 0; j < start.Count; j++)
                    {
                        if (start[j][0] == new BigInteger(-1)) continue;                        
                        if (start[j][0] <= endList[i])
                        {
                            List<BigInteger> nn = new List<BigInteger>();
                            nn.Add(BigInteger.Parse(start[j][0].ToString()));
                            nn.Add(BigInteger.Parse(start[j][1].ToString()));
                            curWork.Add(nn);
                            start[j][0] = new BigInteger(-1);
                        }
                    }

                    doSort(curWork);                    

                    for (int j = curWork.Count - 1; j >= 0; j--)
                    {
                        BigInteger gap = endList[i] - curWork[j][0];
                        if (curWork[j][1] >= end[endList[i]])
                        {
                            curWork[j][1] -= end[endList[i]];
                            newAns += (gap * n - gap * (gap - 1) / 2) * end[endList[i]];
                            end[endList[i]] = 0;
                            break;
                        }
                        else
                        {
                            newAns += (gap * n - gap * (gap - 1) / 2) * curWork[j][1];
                            end[endList[i]] -= curWork[j][1];
                            curWork[j][1] = new BigInteger(0);                            
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1}", caseN, orig - newAns);
            }
            /*
            List<BigInteger>[] list = new List<BigInteger>[101];
            for (int i = 0; i <= 100; i++) list[i] = new List<BigInteger>();
            list[1].Add(new BigInteger(0));
            list[1].Add(new BigInteger(1));
            list[1].Add(new BigInteger(2));
            list[2].Add(new BigInteger(0));
            list[2].Add(new BigInteger(11));
            list[2].Add(new BigInteger(22));

            List<BigInteger> nList = new List<BigInteger>();
            nList.Add(1);
            nList.Add(4);
            nList.Add(9);
            nList.Add(121);
            nList.Add(484);

            for (int i = 3; i <= 51; i++)
            {
                for (int j = i - 2; j >= 1; j -= 2)
                {
                    BigInteger cur = new BigInteger(10);
                    BigInteger curBase = new BigInteger(10);
                    for (int k = 0; k < (i - j) / 2 - 1; k++) { curBase *= 10; cur *= 100; }
                    for (int k = 0; k < j; k++) cur *= 10;
                    cur += 1;

                    for (int k = 0; k < list[j].Count; k++)
                    {
                        cur += list[j][k] * curBase;
                        if (isPal(cur * cur)) { nList.Add(cur * cur); list[i].Add(cur); }
                        cur -= list[j][k] * curBase;
                    }
                }

                for (int j = i - 2; j >= 1; j -= 2)
                {
                    BigInteger cur = new BigInteger(20);
                    BigInteger curBase = new BigInteger(10);
                    for (int k = 0; k < (i - j) / 2 - 1; k++) { curBase *= 10; cur *= 100; }
                    for (int k = 0; k < j; k++) cur *= 10;
                    cur += 2;

                    for (int k = 0; k < list[j].Count; k++)
                    {
                        cur += list[j][k] * curBase;
                        if (isPal(cur * cur)) { nList.Add(cur * cur); list[i].Add(cur); }
                        cur -= list[j][k] * curBase;
                    }
                }
            }

            nList.Sort();

            int T = int.Parse(Console.ReadLine());
            for (int caseN = 1; caseN <= T; caseN++)
            {
                string[] inp = Console.ReadLine().Split();
                BigInteger a = BigInteger.Parse(inp[0]), b = BigInteger.Parse(inp[1]);
                a--;
                int i1 = -1, i2 = -1;
                for (int j = 0; j < nList.Count; j++)
                {
                    if (i1 == -1 && nList[j] > a) i1 = j;
                    if (i2 == -1 && nList[j] > b) { i2 = j; break; }
                }
                Console.WriteLine("Case #{0}: {1}", caseN, i2 - i1);
            }
             * */

        }
    }
}
