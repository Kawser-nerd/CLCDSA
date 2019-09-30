using System;
class B{
  static void Main(){
    var a = Console.ReadLine();
    var b = Console.ReadLine();
    var ans = "";
    for (int i = 0; i < b.Length; i++)
      ans += $"{a[i]}{b[i]}";
    if (a.Length > b.Length)
      ans += a[a.Length - 1];
    Console.WriteLine(ans);
  }
}