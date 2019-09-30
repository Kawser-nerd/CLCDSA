using System;
public class c
{
  public static void Main()
  {
    int n = int.Parse(Console.ReadLine());
    string[] s=Console.ReadLine().Split(' ');
    int sum=0;
    for(int i=0;i<n;i++)
    {
      sum+=int.Parse(s[i]);
    }
  if(sum%2==0)Console.WriteLine("YES");
  else Console.WriteLine("NO");
  }
}