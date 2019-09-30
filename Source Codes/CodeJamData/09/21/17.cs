using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _2009Round2A
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
                  TR = System.IO.File.OpenText("../../A-test.in");
                  TW = System.IO.File.CreateText("../../A-test.out");
                  break;
               case "SMALL":
                  TR = System.IO.File.OpenText("../../A-small.in");
                  TW = System.IO.File.CreateText("../../A-small.out");
                  break;
               case "LARGE":
                  TR = System.IO.File.OpenText("../../A-large.in");
                  TW = System.IO.File.CreateText("../../A-large.out");
                  break;
               default:
                  return;
            }
         }
         catch
         {
            TR = System.IO.File.OpenText("../../A-test.in");
            //return;
         }
         int NumCases = System.Convert.ToInt32(TR.ReadLine());
         for (int i = 0; i < NumCases; i++)
            RunCase(i, TR, TW);
         TR.Close();
         if (TW != null) TW.Close();
      }

      class Node
      {
         double p = 0.0;
         System.String c = "";
         Node t;
         Node f;
         public Node(System.String Str)
         {
            int Start = Str.IndexOf('(');
            if (Start >= 0)
            {
               int Depth = 1;
               int End = Start;
               while (Depth > 0)
               {
                  End++;
                  if (Str[End] == '(') Depth++;
                  else if (Str[End] == ')') Depth--;
               }
               t = new Node(Str.Substring(Start + 1, End - Start - 1));

               System.String[] Param = Str.Substring(0, Start).Split(new char[] { ' ', '\t', '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries);
               p = System.Convert.ToDouble(Param[0]);
               c = Param[1];

               Start = Str.IndexOf('(', End + 1);
               Depth = 1;
               End = Start;
               while (Depth > 0)
               {
                  End++;
                  if (Str[End] == '(') Depth++;
                  else if (Str[End] == ')') Depth--;
               }
               f = new Node(Str.Substring(Start + 1, End - Start - 1));
            }
            else
               p = System.Convert.ToDouble(Str);
         }
         public double Eval(System.String[] Chars)
         {
            if (c == "") return p;
            for (int i = 0; i < Chars.Length; i++)
               if (c == Chars[i]) return p * t.Eval(Chars);
            return p * f.Eval(Chars);
         }
      }

      static void RunCase(int CaseNum, System.IO.TextReader TR, System.IO.TextWriter TW)
      {
         char[] Splits = new char[] { ' ', '\t','\n','\r' };
         int L = System.Convert.ToInt32(TR.ReadLine());
         System.String TreeStr = "";
         for (int i = 0; i < L; i++) TreeStr += TR.ReadLine();
         int Start = TreeStr.IndexOf('(');
         int End = TreeStr.LastIndexOf(')');
         Node N = new Node(TreeStr.Substring(Start+1,End-Start-1));

         System.String Result = "Case #" + (CaseNum + 1) + ":";
         int A = System.Convert.ToInt32(TR.ReadLine());
         for (int i = 0; i < A; i++)
         {
            System.String AStr = TR.ReadLine();
            System.String[] Strs = AStr.Split(Splits, StringSplitOptions.RemoveEmptyEntries);
            int NumChar = System.Convert.ToInt32(Strs[1]);
            System.String[] Chars = new System.String[NumChar];
            for (int j = 0; j < NumChar; j++)
               Chars[j] = Strs[j + 2];
            Result += "\n" + N.Eval(Chars).ToString("0.0000000");
         }


         if (TW == null)
            System.Console.WriteLine(Result);
         else TW.WriteLine(Result);
      }
   }
}
