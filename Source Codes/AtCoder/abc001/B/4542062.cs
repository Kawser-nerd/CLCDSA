using System;

class Program
{
  static void Main(String[] args)
  {
    int dist = int.Parse(Console.ReadLine());
    int vv = 0;
    
    if(dist < 100)
    {
      /* ??? */
    }
    else if(dist <= 5000)
    {
      vv = dist / 100;
    }
    else if(dist <= 30000)
    {
      vv = (dist / 1000) + 50;
    }
    else if(dist <= 70000)
    {
      vv = (((dist /1000)- 30) / 5) + 80;
    }
    else
    {
      vv = 89;
    }
    
    Console.WriteLine(String.Format("{0,0:D2}",vv));
  }
}