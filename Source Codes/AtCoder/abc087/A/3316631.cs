using static System.Console;

class Program {
  static void Main() {
    int x = int.Parse(ReadLine());
    int a = int.Parse(ReadLine());
    int b = int.Parse(ReadLine());
    WriteLine((x - a) % b);
  }
}