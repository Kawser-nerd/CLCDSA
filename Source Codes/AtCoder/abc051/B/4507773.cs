using System; 

class Program 
{ 
    static void Main() 
    {
      var KS = Console.ReadLine().Split();
      var K = int.Parse(KS[0]);
      var S = int.Parse(KS[1]);
      
      var count = 0;
      for (int X=0; X<=K; X++)
      {
        for (int Y=0; Y<=K; Y++)
        {
          if ( (S-(X+Y) > K) || (S < X+Y) ) continue;
          count++;
        }
      }
      Console.WriteLine(count);
    } 
}