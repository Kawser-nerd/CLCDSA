using static System.Console;
class B{
 public static void Main(){
   var s = int.Parse(ReadLine().Split()[0]);
   for (int i = 0; i < s; i++)
   {
     var r = ReadLine();
     WriteLine(r);
     WriteLine(r);
   }
  }
}