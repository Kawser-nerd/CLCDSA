using System;
public class Hello
{public static void Main()
{
  string[] a=Console.ReadLine().Split(' ');
  int A = int.Parse(a[0]);
  int B = int.Parse(a[1]);
  int C = int.Parse(a[2]);//delicious cookie number
  int n = 0;
  if(A+B>=C)Console.WriteLine(B+C);
  else Console.WriteLine(B+C-(C-(A+B+1)));
}
}