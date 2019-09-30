using System;
using System.Linq;
class P{
  static void Main(){
      var b=new string[]{"123456","234561","345612","456123","561234","612345"};
    var a=int.Parse(Console.ReadLine());
    var o=b[a/5%6].ToCharArray();
    for(int i=0;i<a%5;){
      var t=o[i];
      o[i]=o[++i];
      o[i]=t;
    }
    Console.WriteLine(new string(o));
  }
}