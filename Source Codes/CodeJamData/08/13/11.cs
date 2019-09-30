using System;
using System.Collections.Generic;
using System.Text;

namespace Round1C
{
   class Round1C
   {
      static void Main(string[] args)
      {
         System.IO.TextReader TR = null;
         System.IO.TextWriter TW = null;
         try
         {
            switch (args[0].ToUpper())
            {
               case "TEST":
                  TR = System.IO.File.OpenText("../../C-test.in");
                  TW = System.IO.File.CreateText("../../C-test.out");
                  break;
               case "SMALL":
                  TR = System.IO.File.OpenText("../../C-small.in");
                  TW = System.IO.File.CreateText("../../C-small.out");
                  break;
               case "LARGE":
                  TR = System.IO.File.OpenText("../../C-large.in");
                  TW = System.IO.File.CreateText("../../C-large.out");
                  break;
               default:
                  return;
            }
         }
         catch
         {
            TR = System.IO.File.OpenText("../../C-small.in");
            //return;
         }
         int NumCases = System.Convert.ToInt32(TR.ReadLine());
         for (int i = 0; i < NumCases; i++)
            RunCase(i, TR, TW);
         TR.Close();
         if (TW != null) TW.Close();
      }

      static bool IsFac(int a, int n)
      {
         return (n % a) == 0;
      }

      static void MyExp(ref decimal a, ref decimal b,int n)
      {
         decimal Co = 1;
         decimal NewA = 0;
         decimal NewB = 0;
         decimal AMax = a;
         for (int i = 0; i < n; i++)
            AMax *= a;
         decimal BMax = 1;
         decimal Fives = 1;
         for (int i = 0; i <= n; i++)
         {
            if (i > 0)
               Co = Co * (decimal) ((n - i + 1)) / (decimal) i;
            if (a > 0) AMax /= a;
            if (i > 0) BMax *= b;
            if (i > 0 && (i % 2) == 0)
               Fives *= 5;
            if ((i % 2) == 0)
               NewA += Co * AMax * BMax * Fives;
            else
               NewB += Co * AMax * BMax * Fives;
         }
         a = NewA;
         b = NewB;
      }

      static void RunCase(int CaseNum, System.IO.TextReader TR, System.IO.TextWriter TW)
      {
         int Pow = System.Convert.ToInt32(TR.ReadLine());
         if (Pow == 0)
         {
            System.String Result2 = "Case #" + (CaseNum + 1) + ": 001";
            if (TW == null)
               System.Console.WriteLine(Result2);
            else TW.WriteLine(Result2);
            return;
         }
         decimal a = 3;
         decimal b = 1;
         int[] Primes = new int[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
         for (int i = 0; i < Primes.Length; i++)
         {
            while (IsFac(Primes[i], Pow))
            {
               MyExp(ref a, ref b,Primes[i]);
               Pow /= Primes[i];
            }
         }
         decimal Sqrt5 = 2.236067977499789696409173668731276235440618359M;
         decimal Res = (a % 1000) + b * Sqrt5;
         Res = System.Math.Floor(Res);
         decimal k = 1000;
         Res = Res - k * System.Math.Floor(Res / k);

         System.String Result = "Case #" + (CaseNum + 1) + ": " + Res.ToString("000");
         if (TW == null)
            System.Console.WriteLine(Result);
         else TW.WriteLine(Result);
      }
   }
}

