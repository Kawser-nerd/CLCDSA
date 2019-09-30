using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    int n =int.Parse(Console.ReadLine());
    int[] flower =Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    int sum=0;
    for(int i=0;i<n;i++)
    {
      
      if(flower[i]%3==2&&flower[i]%2==0)sum++;
      else if(flower[i]%2==0&&flower[i]%3!=2&&flower[i]%3!=0)sum++;
      else if(flower[i]%2==0&&flower[i]%3==0)sum+=3;
      else if(flower[i]%2!=0&&flower[i]%3==2)sum+=2;
    }
    Console.WriteLine(sum);
  }
}