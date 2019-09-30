using System;
class Program
{
 static void Main(string[] args)
 {
  string[] sS = Console.ReadLine().Trim().Split(' ');
  long lA = long.Parse(sS[0]);
  long lB = long.Parse(sS[1]);
  long lX = long.Parse(sS[2]);
  long lOutA = lA / lX;
  long lOutB = lB / lX;
  long lAdd = 0;
  if (lA % lX == 0) { lAdd += 1; }
  long lOut = lOutB - (lOutA - lAdd);
  Console.WriteLine("{0}", lOut.ToString());
 }
}