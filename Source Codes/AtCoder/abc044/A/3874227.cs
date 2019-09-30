using static System.Console;
class A{
  static void Main(){
    var s = System.Array.ConvertAll(new string[]{ReadLine(),ReadLine(),ReadLine(),ReadLine()},int.Parse);
    WriteLine((s[1]>s[0]?s[0]:s[1])*s[2]+(s[0]>s[1]?s[0]-s[1]:0)*s[3]);
  }
}