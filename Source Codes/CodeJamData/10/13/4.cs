using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using BigNum;

namespace codejam2010
{
    class Program
    {
        static BigInt gongyue(BigInt a, BigInt b)
        {
            if (a == new BigInt("0")) return b;
            if (b == new BigInt("0")) return a;
            if (a > b) { BigInt t = a; a = b; b = t; }
            return gongyue(a, b % a);
        }
        static int D = 0;
        static int I = 0;
        static int M = 0;
       
        static int N3(int a, int b, int c)
        {
            int min = int.MaxValue;
            if (min > N2(a, b)) min = N2(a, b);
            if (min > N2(a, c)) min = N2(a, c);
            if (min > N2(c, b)) min = N2(c, b);
            min = min + D;
            return min;

        }
        static int N2(int a,int b)
        {

            int minsum = int.MaxValue;

            for (int ii1 = 0; ii1 <= 255; ii1++)
                for (int ii2 = 0; ii2 <= 255; ii2++)
                {
                    int change = Math.Abs(ii1 - a) + Math.Abs(ii2 - b);
                    int sum = change;
                    int dis = Math.Abs(ii1 - ii2);

                    if (dis > M)
                    {
                        int D1 = D;
                        //int D2 = dis - M;
                        int D3 = 0;
                        if (M != 0)
                            D3 = ((dis - 1) / M) * I;
                        else
                        {
                            D3 = D1;
                        }
                        if (D3 <= D1) sum = sum + D3;
                        else sum = sum + D1;
                    }
                    else sum = change;
                    if (minsum > sum) minsum = sum;
                }
            return minsum;
        }
        /*
         static void problem1()
        {
            //return;
            StreamReader sr = new StreamReader("test.txt");
            StreamWriter sw = new StreamWriter("result.txt");
           int T = 0;
            BigInt[] group = new BigInt[1005];

            T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string line =
               sr.ReadLine();
                string[] words = line.Split(' ');
                 int N = int.Parse(words[0]);
                int K = int.Parse(words[1]);
               
                line = sr.ReadLine();
                words = line.Split(' ');
                for (int j = 0; j < N; j++)
                {
                    ai[j] = int.Parse(words[j]);
                }

                int sum = 0;
                if (N == 1) sum = 0;
                if (N == 2)
                {
                    sum = N2(ai[0],ai[1]);
                }
                else
                {
                    if (N == 3)
                    {

                        sum = N3(ai[0], ai[1], ai[2]);

                        for (int ii1 = 0; ii1 <= 255; ii1++)
                        {
                            for (int ii2 = 0; ii2 <= 255; ii2++)
                            {
                                for (int ii3 = 0; ii3 <= 255; ii3++)
                                {
                                    int change = Math.Abs(ii1 - ai[0]) + Math.Abs(ii2 - ai[1]) + Math.Abs(ii3 - ai[2]);

                                    if (M == 0)
                                    {
                                        if ((ii1 == ii2) && (ii1 == ii3))
                                        {
                                            if (sum > change) sum = change;
                                        }
                                        continue;
                                    }
                                    int current = 0;
                                    current = change;
                                    int dis1 = Math.Abs(ii1 - ii2);
                                    int dis2 = Math.Abs(ii2 - ii3);

                                    if (M != 0)
                                    {
                                        if (dis1 > M)
                                        {
                                            current += ((dis1 - 1) / M) * I;
                                        }
                                        if (dis2 > M)
                                            current += ((dis2 - 1) / M) * I;

                                        if (current < sum) sum = current;
                                    }
                                    
                                    }
                            }
                        }
                    }
                   
                }
                sw.WriteLine("Case #" + (int)(i + 1) + ": " + sum);
            }
            sw.Close();

        }
         */ 
        static void problem2()
        {
            //return;
            StreamReader sr = new StreamReader("test.txt");
            StreamWriter sw = new StreamWriter("result.txt");
            int T = 0;
            
            T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string line =
               sr.ReadLine();
                string[] words = line.Split(' ');
                int N = int.Parse(words[0]);
                int K = int.Parse(words[1]);
                
                int[][] aij = new int[N][];
                int[][] a = new int[N][];
                

                for (int jj = 0; jj < N; jj++)
                {
                    aij[jj] = new int[N];
                    a[jj] = new int[N];

                    line = sr.ReadLine();
                    
                    for (int j = 0; j < N; j++)
                    {
                        if (line[j] == '.') 
                        aij[jj][j] = 0;
                    if (line[j] == 'R')
                        aij[jj][j] = 1;
                    if (line[j] == 'B')
                        aij[jj][j] = 2;

                    }
                }

                for (int ii1 = 0; ii1 < N; ii1++)
                    for (int ii2 = 0; ii2 < N; ii2++)
                    {
                        a[ii1][ii2] = aij[N - 1 - ii2][ii1];
                    }
                int[] TT = new int[N];
                int size = 0;
                
                for (int y = 0; y < N; y++)
                {
                    size = N -1;
                    for (int x = N - 1; x >= 0; x--)
                    {
                        if (a[x][y] != 0)
                        {
                            a[size][y] = a[x][y];
                            if (x != size)
                            {
                                a[x][y] = 0;
                            }
                                size--;
                        }
                    }
                }
               
                bool fblue = false;
                bool fred = false;
                for (int x = 0; x < N;x++)
                    for (int y = 0; y < N; y++)
                    {
                        if (y + K <= N)
                        {
                            bool red = true;
                            bool blue = true;

                            for (int z = y; z <= y + K - 1; z++)
                            {
                                if (a[x][z] == 0)
                                {
                                    red = false;
                                    blue = false;
                                    break;
                                }
                                if (a[x][z] == 1)
                                {
                                   
                                    blue = false;
                                   
                                }
                                if (a[x][z] == 2)
                                {
                                    red = false;
                                }
                            }
                            if (red) fred = true;
                            if (blue) fblue = true;
                        
                        }

                        if (x + K <= N)
                        {
                            bool red = true;
                            bool blue = true;

                            for (int z = x; z <= x + K - 1; z++)
                            {
                                if (a[z][y] == 0)
                                {
                                    red = false;
                                    blue = false;
                                    break;
                                }
                                if (a[z][y] == 1)
                                {

                                    blue = false;

                                }
                                if (a[z][y] == 2)
                                {
                                    red = false;
                                }
                            }
                            if (red) fred = true;
                            if (blue) fblue = true;

                        }

                        if ((y + K <= N) && (x + K <=N))
                        {
                            bool red = true;
                            bool blue = true;

                            for (int z = 0; z <= K - 1; z++)
                            {
                                if (a[ x + z][z +y] == 0)
                                {
                                    red = false;
                                    blue = false;
                                    break;
                                }
                                if (a[x + z][z + y] == 1)
                                {

                                    blue = false;

                                }
                                if (a[x + z][z + y] == 2)
                                {
                                    red = false;
                                }
                            }
                            if (red) fred = true;
                            if (blue) fblue = true;

                        }

                        if ((y >= K - 1) && (x + K <= N))
                        {
                            bool red = true;
                            bool blue = true;

                            for (int z = 0; z <= K - 1; z++)
                            {
                                if (a[x + z][y - z] == 0)
                                {
                                    red = false;
                                    blue = false;
                                    break;
                                }
                                if (a[x + z][y - z] == 1)
                                {

                                    blue = false;

                                }
                                if (a[x + z][y - z] == 2)
                                {
                                    red = false;
                                }
                            }
                            if (red) fred = true;
                            if (blue) fblue = true;

                        }
                        if ((fred) && (fblue)) break;
                    }
                if ((fred) && (fblue))
                sw.WriteLine("Case #" + (int)(i + 1) + ": " + "Both");

            if ((fred) && (!fblue))
                sw.WriteLine("Case #" + (int)(i + 1) + ": " + "Red");

            if ((!fred) && (fblue))
                sw.WriteLine("Case #" + (int)(i + 1) + ": " + "Blue");

            if ((!fred) && (!fblue))
                sw.WriteLine("Case #" + (int)(i + 1) + ": " + "Neither");
            }
            sw.Close();

        }


        static bool pan(int a, int b)
        
        {
            
            
            
            
            if (a == b) return false;
            if (a % b == 0) return true;
            if (b % a == 0) return true;

            if (a < b)
            {
                int T = 0;
                T = a;
                a = b;
                b = T;
            }

            int shang = a / b;
            int yu = a % b;

            for (int i = 0; i < shang; i++)
            {
                bool T = pan(yu + i * b, b);
                if (!T) return true;

            }
            return false;

        }
        static void problem3()
        {
             StreamReader sr = new StreamReader("test.txt");
            StreamWriter sw = new StreamWriter("result.txt");
            int T = 0;
            
            T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
               string line =
               sr.ReadLine();

                string[] words = line.Split(' ');
                int A1 = int.Parse(words[0]);
                int A2 = int.Parse(words[1]);
                int B1 = int.Parse(words[2]);
                int B2 = int.Parse(words[3]);

                int sum = 0;
                for (int a = A1; a<= A2; a++)
                    for (int b = B1; b <= B2; b++)
                    {
                        if (pan(a, b)) sum++;

                    }
                sw.WriteLine("Case #" + (int)(i + 1) + ": " + sum);
            }
            sw.Close();  
                
        }
        static void Main(string[] args)
        {
            problem3();
            return;
        }

        static void t2_Main(string[] args)
        {
            //Console.WriteLine(gongyue(3011,2545));
            //return;
            StreamReader sr = new StreamReader("test.txt");
            StreamWriter sw = new StreamWriter("result.txt");
            int N = 0;
            int T = 0;
            BigInt[] group = new BigInt[1005];
            
            T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
             //   N = int.Parse(sr.ReadLine());

                string[] words = sr.ReadLine().Split(' ');

                N = int.Parse(words[0]);
                for (int j = 0; j < N; j++)
                {
                    group[j] = new BigInt((words[j+1]));
                   
                }

                for (int j = 0; j < N - 1; j++)
                {
                    for (int jj = j+ 1; jj < N; jj++)
                    {
                        if (group[j] > group[jj]) {BigInt t = group[j];group[j] = group[jj];group[jj] = t;}
                    }
                }
                for (int j = 0; j < N; j++)
                    Console.Write(group[j] + " ");
                Console.WriteLine();
                BigInt g = group[1] - group[0];
                for (int j = 1; j < N-1; j++)
                {
                    g = gongyue(g, group[j + 1] - group[j]);
                }
                        BigInt shu = new BigInt("0");
                        if (g>new BigInt("1") && group[0]%g!=new BigInt("0")) shu = g - group[0] % g;
                        sw.WriteLine("Case #" + (int)(i + 1) + ": " + shu);
            }
            sw.Close();
        }
        static void t3_Main(string[] args)
        {
          
            StreamReader sr = new StreamReader("test.txt");
            StreamWriter sw = new StreamWriter("result.txt");
            int N = 0;
            Int64  K = 0;
            int T = 0;
            int R = 0;

            T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                
                
                string line = sr.ReadLine();
                string[] words = line.Split(' ');

                R = int.Parse(words[0]);
                K = int.Parse(words[1]);
                N = int.Parse(words[2]);

                int light = 0;
                int[] group = new int[N];

                long[] cost = new long[N];
                int[] next = new int[N];

                line = sr.ReadLine();
                words = line.Split(' ');

                Int64 allsum = 0;
                for (int j = 0; j < N; j++)
                {
                    group[j] = int.Parse(words[j]);
                    allsum += group[j];
                
                }
                if (allsum <= (Int64)K) { sw.WriteLine("Case #" + (int)(i + 1) + ": " + (Int64)allsum * (Int64)R); continue; }

                allsum = 0;
                int index = 0;
                R = R - 1;
                for (int j = 0; j < N; j++)
                {
                    long sum = 0;
                    index = j;
                    while (sum + group[index] <= K) { sum += group[index]; index++; index = index % N; }
                    cost[j] = sum;
                    next[j] = index;
                }
                /*
                int qq = 0;
                for (int ii = 0; ii <= R; ii++)
                {
                    allsum = allsum + cost[qq];
                    qq = next[qq];
                }
                */
                
                int[] cycle = new int[2000];
                for (int ii = 0; ii < 2000; ii++)
                {
                    cycle[ii] = 0;
                }
                index = 0; cycle[0] = 0;
                int k = 0;
                while (true)
                {
                    index++;
                    cycle[index] = next[cycle[index - 1]];
                    k = -1;
                    for (int j = 0; j < index; j++)
                    {
                        if ((cycle[j] == cycle[index])) { k = j; break; }
                    }
                    if (k != -1) break;
                }
                if (R <= k)
                {
                    for (int jj = 0; jj <= R; jj++)
                    {
                        allsum = allsum + cost[cycle[jj]];
                    }
                }
                else
                {
                    for (int jj = 0; jj < k; jj++)
                    {
                        allsum = allsum + cost[cycle[jj]];

                    }
                    int shang = (R - k) / (index - k);
                    int yu = (R - k) % (index - k);
                    Int64 xsum = 0;
                    for (int jj = k; jj < index; jj++)
                    {
                        xsum = xsum + cost[cycle[jj]];
 
                    }
                    allsum = allsum + xsum * shang;
                    
                    for (int jj = k; jj <= k + yu; jj++)
                    {
                        allsum = allsum + cost[cycle[jj]];

                    }
                    
                }
                 
                    sw.WriteLine("Case #" + (int)(i + 1) + ": " + allsum);
              

            }
            sw.Close();
        }
        static void t_1small_Main(string[] args)
        {
            StreamReader sr = new StreamReader("test.txt");
            StreamWriter sw = new StreamWriter("result.txt");
            int N = 0;
            int K = 0;
            int T = 0;
            T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string line = sr.ReadLine();
                string[] words = line.Split(' ');
                
                N = int.Parse(words[0]);
                K = int.Parse(words[1]);

                int light = 0;
                int[] state = new int[N];
                int[] power = new int[N];


                for (int j = 0; j < N; j++)
                {
                    state[j] = -1;
                    power[j] = -1;
                }
                power[0] = 1;

                for (int j = 0; j < K; j++)
                {
                    for (int jj = 0; jj < N; jj++)
                    {
                   if (power[jj] == 1) state[jj] = -state[jj];
                  if (jj > 0) 
                  {
                      if ( (power[jj - 1] == 1) && (state[jj - 1] == 1)) power[jj] = 1;
                     
                  }
                  if (jj > 0)
                  {
                      if ((power[jj - 1] != 1) || (state[jj - 1] != 1)) power[jj] = -1;
                     
                  }

                  }
                }
                if (
                    (power[N - 1] == 1) && (state[N - 1] == 1))
                    sw.WriteLine("Case #" + (int)(i + 1) + ": " + "ON");
                else   sw.WriteLine("Case #" + (int)(i + 1) + ": " + "OFF");
               
            }
            sw.Close();
        }
        static void t_1_large_Main(string[] args)
        {
            StreamReader sr = new StreamReader("test.txt");
            StreamWriter sw = new StreamWriter("result1.txt");
            int N = 0;
            int K = 0;
            int T = 0;
            T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string line = sr.ReadLine();
                string[] words = line.Split(' ');

                N = int.Parse(words[0]);
                K = int.Parse(words[1]);

                K++;
                int light = 0;
                for (int ii = 0; ii < N; ii++)
                {
                    if ( (K % 2) == 1) {light = 1; break;}
                K = K / 2;
                }
                   if (light == 0) 
                    sw.WriteLine("Case #" + (int)(i + 1) + ": " + "ON");
                else sw.WriteLine("Case #" + (int)(i + 1) + ": " + "OFF");

            }
            sw.Close();
        }
    }
}
