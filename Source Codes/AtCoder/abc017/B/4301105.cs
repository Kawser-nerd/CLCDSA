using System;

class Program
{
  public static void Main(string[] args)
  {
    string s = Console.ReadLine();
    Console.WriteLine(choku(s) ? "YES" : "NO");
  }
  public static bool choku(string x) {
    int result = 0;
    for (int i = 0; i < x.Length; i ++) {
      string s = x[i].ToString();
      if (s == "o" || s == "k" || s == "u") result ++;
      if (s == "c" && x[i+1].ToString() == "h") {
        result += 2;
        i ++;
      }
    }
    return result == x.Length;
  }
}