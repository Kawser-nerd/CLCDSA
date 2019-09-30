using static System.Console;
class A{
  static void Main(){
    var s = ReadLine();
    var n = int.Parse(ReadLine())-1;
    WriteLine($"{s[n/5]}{s[n%5]}");
  }
}