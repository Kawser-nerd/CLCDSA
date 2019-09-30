using System;
class Program
{
  static void Main(string[] args) {
    int cs = int.Parse(Console.ReadLine());
    for (int ci = 1 ; ci <= cs ; ci++) {
      string s = Console.ReadLine();
      Console.WriteLine("Case #" + ci + ": " + Solve(s));
    }
  }

  static int Solve(string cake) {
    int len = cake.Length;
    int ans = 0;
    for (int i = 1 ; i < len ; i++) {
      if (cake[i-1] != cake[i]) {
        ans++;
      }
    }
    return ans + ((cake[len-1] == '+') ? 0 : 1);
  }
}
