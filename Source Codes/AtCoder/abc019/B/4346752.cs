using System;

class Program
{
  public static void Main(string[] args)
  {
    string str = Console.ReadLine();
    char[] s = (str + "1").ToCharArray();
    string result = "";
    int count = 0;
    for (int i = 1; i < s.Length; i ++) {
      count ++;
      if (s[i] != s[i-1]) {
        result += s[i-1].ToString() + count.ToString();
        count = 0;
      }
    }
    Console.WriteLine(result);
  }
}