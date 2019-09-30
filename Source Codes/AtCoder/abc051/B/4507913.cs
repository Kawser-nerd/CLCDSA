using System; 

class Program 
{ 
    static void Main() 
    {
      var KS = Console.ReadLine().Split();
      var K = int.Parse(KS[0]);
      var S = int.Parse(KS[1]);
      var ans = ( S<2*K ? -(S>K?1:0)*(K-=S)*--K*3 + ++S*++S : (S-=1+3*K)*--S ) / 2;
      Console.WriteLine(ans);
    } 
}