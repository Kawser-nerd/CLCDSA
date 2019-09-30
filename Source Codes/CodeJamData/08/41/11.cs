using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static Int64 sum;
        static int[] T;
        
        static int C;
        static int Number;
       
        static Int64[] result;
        static int[] finalresult;
        static int final;
        static Int64[] miles;

        static StreamWriter sw1 = new StreamWriter("out1.txt");
          
        
        public static void cal(int N)
        {

            if (N == 0)
            {
                bool test = true;

                Int64 tmp = -1;
                Int64 tmp2 = 0;
                for (int i = 0; i < Number; i++)
                {
                    sw1.Write(result[i]);
                    if (result[i] == 0)
                    {
                        tmp2++;
                        if (tmp >= miles[i])
                        {
                            test = false;

                        }
                        tmp = miles[i];
                    }
                    
                    }
                    if ((test) && (tmp != -1)) sum++;
                    sw1.WriteLine();
                }
               
            else 
            {
                result[N - 1] = 1;
                cal(N - 1);
                
                result[N - 1] = 0;
                cal(N - 1);
            }

            //if (N > 0) 

        }
        
        static void Main(string[] args)
        {

            StreamReader sr = new StreamReader("A-large.in");
            StreamWriter sw = new StreamWriter("out.txt");
            string line = sr.ReadLine();
            C = int.Parse(line);

            for (int i = 0; i < C; i++)
            {
                final = 10000;
                line = sr.ReadLine();
                
                string[] numlist = line.Split(new char[] { ' ' });

                int M = int.Parse(numlist[0]);
                int V = int.Parse(numlist[1]);
                
                int[] Change = new int[M + 1];
                int[] num0 = new int[M + 1];
                int[] num1 = new int[M + 1];

                int[] A = new int[M + 1];
                int[] Gate = new int[M + 1];
               
                for (int ii = 1; ii <= (M - 1)/2; ii++)
                {
                    line = sr.ReadLine();
                    string[] numlist2 = line.Split(new char[] { ' ' });

                    A[ii] = 0;
                    num0[ii] = -1;
                    num1[ii] = -1;
                    Gate[ii] = int.Parse(numlist2[0]);
                    Change[ii] = int.Parse(numlist2[1]);

                }

                for (int ii = (M + 1)/2; ii <= M; ii++)
                {
                    line = sr.ReadLine();
                   
                    A[ii] = int.Parse(line);
                    if (A[ii] == 0) 
                    {num0[ii] = 0;
                    num1[ii] = -1;
                    }
                    else {num0[ii] = -1;
                    num1[ii] = 0;
                    } 
                }
             
                int j = M;
                while (j >= 1)
                {
                    if (j >= (M + 1) / 2) { j = j - 1; continue; }
                    if (Gate[j] == 0)
                    {
                        if ((num1[j * 2] != -1) || (num1[j * 2 + 1] != -1))
                        {
                            int tmp = 10000;
                            if (num1[j * 2] != -1) tmp = num1[j * 2];
                            if ((num1[j * 2 + 1] != -1) && (tmp > num1[j * 2 + 1])) tmp = num1[j * 2 + 1];
                            num1[j] = tmp;
                        }

                        else num1[j] = -1;

                        if ((num0[j * 2] != -1) && (num0[j * 2 + 1] != -1))
                        {
                            num0[j] = num0[j * 2 + 1] + num0[j * 2];
                        }
                        else num0[j] = -1;

                    }
                    if (Gate[j] == 1)
                    {
                        if ((num1[j * 2] != -1) && (num1[j * 2 + 1] != -1))
                        {
                            num1[j] = num1[j * 2 + 1] + num1[j * 2];
                        }
                        else num1[j] = -1;

                        if ((num0[j * 2] != -1) || (num0[j * 2 + 1] != -1))
                        {
                            int tmp = 10000;
                            if (num0[j * 2] != -1) tmp = num0[j * 2];
                            if ((num0[j * 2 + 1] != -1) && (tmp > num0[j * 2 + 1])) tmp = num0[j * 2 + 1];
                            num0[j] = tmp;
                        }
                        else num0[j] = -1;

                    }
                    if (Change[j] == 0)
                    {
                        
                    }
                    else
                    {
                        if (Gate[j] == 1)
                        {
                            if ((num1[j * 2] != -1) || (num1[j * 2 + 1] != -1))
                            {
                                int tmp = 10000;
                                if (num1[j * 2] != -1) tmp = num1[j * 2];
                                if ((num1[j * 2 + 1] != -1) && (tmp > num1[j * 2 + 1])) tmp = num1[j * 2 + 1];
                                if ((num1[j]  > tmp + 1) || (num1[j] == -1))  num1[j] = tmp + 1;
                            }

                            //else num1[j] = -1;

                            if ((num0[j * 2] != -1) && (num0[j * 2 + 1] != -1))
                            {
                                int tmp = num0[j * 2 + 1] + num0[j * 2];
                            if ((num0[j]  > tmp + 1) || (num0[j] == -1))  num0[j] = tmp + 1;
                            }
                           // else num0[j] = -1;

                        }
                        if (Gate[j] == 0)
                        {
                            if ((num1[j * 2] != -1) && (num1[j * 2 + 1] != -1))
                            {
                                int tmp = num1[j * 2 + 1] + num1[j * 2];
                                if ((num1[j] > tmp + 1) || (num1[j] == -1)) num1[j] = tmp + 1;
                           
                            }
                            //else num1[j] = -1;

                            if ((num0[j * 2] != -1) || (num0[j * 2 + 1] != -1))
                            {
                                int tmp = 10000;
                                if (num0[j * 2] != -1) tmp = num0[j * 2];
                                if ((num0[j * 2 + 1] != -1) && (tmp > num0[j * 2 + 1])) tmp = num0[j * 2 + 1];
                                if ((num0[j] > tmp + 1) || (num0[j] == -1)) num0[j] = tmp + 1;
                               
                            }

                            //else num0[j] = -1;

                        }
                    }
                    j = j - 1;
                }
                string results = "";
                if ((V == 0) && (num0[1] != -1)) results = num0[1].ToString();
                if ((V == 1) && (num1[1] != -1)) results = num1[1].ToString();
                if ((V == 0) && (num0[1] == -1)) results = "IMPOSSIBLE";
                if ((V == 1) && (num1[1] == -1)) results = "IMPOSSIBLE";
              
              //cal(n);
               //for (int k = 0; k < 
             
                sw.WriteLine("Case #" + (int)(i + 1) + ": " + results);
            }
            sr.Close();
            sw.Close();
            sw1.Close();
        }
    }
}
