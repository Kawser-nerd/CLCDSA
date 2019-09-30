using System;
public class c
{
  public static void Main()
  {
    string[] A_B_K = Console.ReadLine().Split(' ');
    int A = int.Parse(A_B_K[0]);
    int B = int.Parse(A_B_K[1]);
    int K = int.Parse(A_B_K[2]);
    int n = A;
    int ans =0;
    if(n>B) n=B;
    for(int i=n;i>=1;i--)
    {
      if(A%i==0&&B%i==0)K--;
      if(K==0){ans=i;break;}
    }
    Console.WriteLine(ans);
    
  }
}