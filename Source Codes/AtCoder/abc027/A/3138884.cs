using System;
class Program
{
 static void Main(string[] args)
 {
  string[] S = Console.ReadLine().Trim().Split(' ');
  string t = "";
  if (S[0] == S[1]) { t = S[2]; }
  if (S[0] == S[2]) { t = S[1]; }
  if (S[1] == S[2]) { t = S[0]; }
  Console.WriteLine("{0}", t.ToString());
 }
}