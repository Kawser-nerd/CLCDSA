using System;
using System.Linq;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    string s = Console.ReadLine();
    string t = Console.ReadLine();
    string u = "@atcoder";
    bool f = true;
    var win = "You can win";
    var lose = "You will lose";
    for (int i = 0; i < s.Length; i ++)
    {
      if (s[i] == t[i]) continue;
      else
      {
        if (s[i] == u[0] && u.Contains(t[i])) continue;
        else if (t[i] == u[0] && u.Contains(s[i])) continue;
        else f = false; break;
      }
    }
    if (f) Console.WriteLine("You can win");
    else Console.WriteLine("You will lose");
  }
}