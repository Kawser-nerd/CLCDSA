using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamR1C3
{
    class Program
    {

        static Dictionary<String, long> dic = new Dictionary<string, long>();


      

        public static long dp(long[] numM,int[] typeM,long[] numN,int[] typeN,long nowM,long nowN,int idM,int idN)
        {
            if (nowM == numM[numM.Length - 1] || nowN == numN[numN.Length - 1])
                return 0;

            string key =  nowM+" "+nowN;

            if (dic.ContainsKey(key))
                return dic[key];


            //Console.WriteLine(nowM+" "+nowN);
            //Console.WriteLine(idM + " " + idN);
            //Console.WriteLine("-----------------------");

            long result = 0;

            

             if (typeM[idM] == typeN[idN])
             {
                 long vM = numM[idM] - nowM;
                 long vN = numN[idN] - nowN;

                 long min = vM < vN ? vM : vN;



                 int newIdM = (min == vM) ? idM + 1 : idM;
                 int newIdN = (min == vN) ? idN + 1 : idN;


                 //Console.WriteLine("(((((((((((((((((");
                 //Console.WriteLine(nowM + " " + nowN);
                 //Console.WriteLine(idM + " " + idN);
                 //Console.WriteLine(vM + " " + vN);
                 //Console.WriteLine((nowM + min) + " " + (nowN + min));
                 //Console.WriteLine(newIdM + " " + newIdN);
                 //Console.WriteLine("))))))))))))))))))");

                 long result3 = dp(numM, typeM, numN, typeN, nowM + min, nowN + min, newIdM, newIdN) + min;


                 result = result3 > result ? result3 : result;
             }
             else
             {
                 long result1 = dp(numM, typeM, numN, typeN, numM[idM], nowN, idM + 1, idN);
                 long result2 = dp(numM, typeM, numN, typeN, nowM, numN[idN], idM, idN + 1);

                 result = result1 > result2 ? result1 : result2;
             }



            dic.Add(key, result);

           // if (dic.Count % 1000 == 0)
             //   Console.WriteLine(dic.Count);

                return result;
          //  if()
        }

        static void Main(string[] args)
        {


            StreamReader sr = new StreamReader(@"D:\codejam\C-small-attempt1.in");
           // StreamReader sr = new StreamReader(@"D:\codejam\input.txt");
            StreamWriter sw = new StreamWriter(@"D:\codejam\output.txt");

            int T = Int32.Parse(sr.ReadLine());

           

            for (int t = 0; t < T; t++)
            {
                dic.Clear();

                string[] ss = sr.ReadLine().Split(' ');

                int N = Int32.Parse(ss[0]);
                int M = Int32.Parse(ss[1]);

                int[] typeN=new int[N];
                long[] numN = new long[N];

                int[] typeM = new int[M];
                long[] numM = new long[M];

                ss = sr.ReadLine().Split(' ');

                for (int i = 0; i < N; i++)
                {
                    if(i==0)
                        numN[i] = Int64.Parse(ss[i * 2]);
                    else
                        numN[i] = Int64.Parse(ss[i * 2])+numN[i-1];

                    typeN[i] = Int32.Parse(ss[i * 2+1]);
                }

                ss = sr.ReadLine().Split(' ');

                for (int i = 0; i < M; i++)
                {
                    if (i == 0)
                        numM[i] = Int64.Parse(ss[i * 2]);
                    else
                        numM[i] = Int64.Parse(ss[i * 2]) + numM[i - 1];
                    
                    typeM[i] = Int32.Parse(ss[i * 2 + 1]);
                }

                //for (int i = 0; i < N; i++)
                //    sw.WriteLine(numN[i] + " " + typeN[i]);

                //sw.WriteLine();
                //for (int i = 0; i < M; i++)
                //    sw.WriteLine(numM[i] + " " + typeM[i]);

                sw.WriteLine("Case #"+(t+1)+": "+dp(numM,typeM,numN,typeN,0,0,0,0));
                sw.Flush();
             //   Console.ReadLine();

            }

            sr.Close();
            sw.Close();
        }
    }
}
