using System; 

class Program 
{ 
    static void Main() 
    {
      var N = int.Parse(Console.ReadLine());
      var x = new int[N];
      var y = new int[N];
      for (int i=0; i<N; i++)
      {
        var xy = Console.ReadLine().Split();
        x[i] = int.Parse(xy[0]);
        y[i] = int.Parse(xy[1]);
      }
      double D = 0;
      for (int j=0; j<N; j++)
      {
        for (int k=0; k<N; k++)
        {
          var d = Math.Sqrt( Math.Pow(x[j]-x[k], 2) + Math.Pow(y[j]-y[k], 2) );
          if ( D < d ) D = d;       
        }
      }
      Console.WriteLine(D);
    } 
}