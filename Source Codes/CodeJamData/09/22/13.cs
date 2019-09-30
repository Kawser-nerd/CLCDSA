using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _2009Round2B
{
   static class Program
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
                  TR = System.IO.File.OpenText("../../B-test.in");
                  TW = System.IO.File.CreateText("../../B-test.out");
                  break;
               case "SMALL":
                  TR = System.IO.File.OpenText("../../B-small.in");
                  TW = System.IO.File.CreateText("../../B-small.out");
                  break;
               case "LARGE":
                  TR = System.IO.File.OpenText("../../B-large.in");
                  TW = System.IO.File.CreateText("../../B-large.out");
                  break;
               default:
                  return;
            }
         }
         catch
         {
            TR = System.IO.File.OpenText("../../B-test.in");
            //return;
         }
         int NumCases = System.Convert.ToInt32(TR.ReadLine());
         for (int i = 0; i < NumCases; i++)
            RunCase(i, TR, TW);
         TR.Close();
         if (TW != null) TW.Close();
      }

      static System.String MinString(System.String input)
      {
         System.String Result = "";
         int[] count = new int[10];
         for (int i = 0; i < input.Length; i++)
            count[(int) (input[i]-'0')]++;
         for (int i = 0; i < 10; i++)
            while (count[i]-- > 0)
               Result += (char)(i + '0');
         return Result;
      }

      static void RunCase(int CaseNum, System.IO.TextReader TR, System.IO.TextWriter TW)
      {
         char[] Splits = new char[] { ' ', '\t' };
         System.String Str = "0" + TR.ReadLine();
         System.String BestStr = "";

         for (int i = 1; i < Str.Length; i++)
            for (int j = 0; j < i; j++)
            {
               System.String NewStr = Str.Substring(0, j) + Str[i] + MinString(Str.Substring(j, i - j) + Str.Substring(i + 1));
               if ((BestStr == "" || NewStr.CompareTo(BestStr)<0) && NewStr.CompareTo(Str) >0) BestStr = NewStr;
            }

         if (BestStr[0] == '0') BestStr = BestStr.Substring(1);

         System.String Result = "Case #" + (CaseNum + 1) + ": " + BestStr;
         if (TW == null)
            System.Console.WriteLine(Result);
         else TW.WriteLine(Result);
      }
   }
}
