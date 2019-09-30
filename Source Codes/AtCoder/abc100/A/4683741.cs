using System;
public class Program {
  public static void Main(string[] args) {
    string[] tmp = Console.ReadLine().Split(' ');
    int A = int.Parse(tmp[0]);
    int B = int.Parse(tmp[1]);
    
    int max = A > B ? A : B;
    if(max*2 <= 16) {
      Console.WriteLine("Yay!");
    }
    else {
      Console.WriteLine(":(");
    }
  }
}