using System;
using System.Collections.Generic;
//using System.Linq;
class Program
{
  //static List<string> list;
  static List<int> primes = new List<int>{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,
                                59,61,67,71,73,79,83,89,97};
	static void Main(string[] args)
	{
		// ??????
        int N = int.Parse(Console.ReadLine());

        // 75????????
        // ????????? A^74
        // ????????? A^2 * B^24, A^4 * B^14
        // ????????? A^2 * B^4 * C^4 ?????A != B != C != A?

        // N!???????
        int[] kaijo = new int[N];
        for(int i=1; i<=N; i++)
        {
          kaijo[i-1] = i;
        }

        int ret = count75divisor_1(kaijo);
        ret += count75divisor_2_1(kaijo);
        ret += count75divisor_2_2(kaijo);
        ret += count75divisor_3(kaijo);


    // ??
        Console.WriteLine(ret);
    }
		class layer{ //?????
			public long total {set; get;} // ?????
			public long paty {set; get;}  // ?????
      public long banz {set; get;}  // ?????
		}
    static private int count75divisor_3(int[] kaijo)
    {
        int ret = 0;
        // 1~100????????????A^2 * B^4 * C^4???????
        for(int i=0; i<primes.Count-2; i++)
        {
          for(int j=i+1; j<primes.Count-1; j++)
          {
            for(int h=j+1; h<primes.Count; h++)
            {
              int a = primes[i];
              int b = primes[j];
              int c = primes[h];
              if(c > kaijo.Length) break;
              int[] temp = new int[kaijo.Length];
              Array.Copy(kaijo, temp, kaijo.Length);
              int k = 0, pa = 0, pb = 0, pc = 0;
              while(true)
              {
                if(k >= temp.Length) break;

                if(temp[k]%a == 0)
                {
                  temp[k] /= a;
                  pa ++ ;
                }else if(temp[k]%b == 0)
                {
                  temp[k] /= b;
                  pb++;
                }
                else if(temp[k]%c == 0)
                {
                  temp[k] /= c;
                  pc++;
                }
                else
                {
                  k++;
                }
              }
              if(pa >= 2 && pb >= 4 && pc >= 4) ret++;
              if(pa >= 4 && pb >= 2 && pc >= 4) ret++;
              if(pa >= 4 && pb >= 4 && pc >= 2)ret++;


              //Console.WriteLine("????3 " + a + "¥^" + pa + " " + b + "¥^" + pb
              //+ " " + c + "¥^" + pc + " " + f);
            }

          }

        }

        return ret;
    }
    static private int count75divisor_2_2(int[] kaijo)
    {
        int ret = 0;
        // 1~100????????????A^4 * B^14???????
        for(int i=0; i<primes.Count-1; i++)
        {
          for(int j=i+1; j<primes.Count; j++)
          {
            int a = primes[i];
            int b = primes[j];
            if(b > kaijo.Length) break;
            int[] temp = new int[kaijo.Length];
            Array.Copy(kaijo, temp, kaijo.Length);
            int k = 0, pa = 0, pb = 0;
            while(true)
            {
              if(k >= temp.Length) break;

              if(temp[k]%a == 0)
              {
                temp[k] /= a;
                pa ++ ;
              }else if(temp[k]%b == 0)
              {
                temp[k] /= b;
                pb++;
              }
              else
              {
                k++;
              }
            }
            if(pa >= 4 && pb >= 14) ret ++;
            if(pa >= 14 && pb >= 4) ret ++;

            //Console.WriteLine("????2-2 " + a + "¥^" + pa + " " + b + "¥^" + pb + " " + f);
          }

        }

        return ret;
    }
    static private int count75divisor_2_1(int[] kaijo)
    {
        int ret = 0;
        // 1~100????????????A^2 * B^24???????
        for(int i=0; i<primes.Count-1; i++)
        {
          for(int j=i+1; j<primes.Count; j++)
          {
            int a = primes[i];
            int b = primes[j];
            if(b > kaijo.Length) break;

            int[] temp = new int[kaijo.Length];
            Array.Copy(kaijo, temp, kaijo.Length);
            int k = 0, pa = 0, pb = 0;
            while(true)
            {
              if(k >= temp.Length) break;

              if(temp[k]%a == 0)
              {
                temp[k] /= a;
                pa ++ ;
              }else if(temp[k]%b == 0)
              {
                temp[k] /= b;
                pb++;
              }
              else
              {
                k++;
              }
            }
            if(pa >= 2 && pb >= 24) ret++;
            if(pa >= 24 && pb >= 2) ret++;

            //Console.WriteLine("????2-1 " + a + "¥^" + pa + " " + b + "¥^" + pb + " " + f);
          }

        }

        return ret;
    }
    static private int count75divisor_1(int[] kaijo)
    {
        int ret = 0;
        // 1~100?????A^74???????
        for(int i=0; i<primes.Count; i++)
        {

          if(primes[i] > kaijo.Length) break; //N?????????????????????
          int[] temp = new int[kaijo.Length];
          Array.Copy(kaijo, temp, kaijo.Length);
          int k = 0, p = 0;
          while(true)
          {
            if(k >= temp.Length) break;
            //Console.Write(temp[k] + " ");
            if(temp[k]%primes[i] == 0)
            {
              temp[k] /= primes[i];
              p ++ ;
            }else
            {
              k++;
            }
          }

          if(p>=74)
          {
            ret++;
          }
          //Console.WriteLine("????1 " + primes[i] + "¥^" + p + " " + f);
        }

        return ret;
    }



}