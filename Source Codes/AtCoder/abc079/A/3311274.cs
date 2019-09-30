using System;

class Program {
  static void Main() {
    string n = Console.ReadLine();
    if ((n[0]==n[1]&&n[1]==n[2])||(n[1] == n[2] && n[2] == n[3])) {
      Console.WriteLine("Yes");
    } else {
      Console.WriteLine("No");
    }
  }
}