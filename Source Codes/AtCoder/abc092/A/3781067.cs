using static System.Console;
using static System.Math;
class A{
  public static void Main(){
    var s = System.Array.ConvertAll(new string[] { ReadLine(), ReadLine(), ReadLine(), ReadLine() }, int.Parse);
    WriteLine(Min(s[0], s[1]) + Min(s[2], s[3]));
  }
}