using static System.Console;
class A{
 static void Main(){
   var a = ReadLine();
   var b = ReadLine();
   WriteLine(a.Length > b.Length?a:b);
 }
}