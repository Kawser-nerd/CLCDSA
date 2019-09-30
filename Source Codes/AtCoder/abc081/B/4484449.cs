using System;
public class c
{
  public static void Main()
  {
    int n=int.Parse(Console.ReadLine());
    string[] s = Console.ReadLine().Split(' ');
    int count =0;
    int min  =99999999;
    int x=0;
    for(int i=0;i<n;i++)
    {
      x=int.Parse(s[i]);
      while(true)
      {
        if(x%2!=0)break;
        x=x/2;
        count ++; 
      }
      if(count<min)min=count;
      count=0;
   
        
    }
    Console.WriteLine(min);
  }
}