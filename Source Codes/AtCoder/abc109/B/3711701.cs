using System;
using System.Linq;
class P{
  static void Main(){
    var s=int.Parse(Console.ReadLine());
    var l=new string[s];
    l[0]=Console.ReadLine();
    char a=l[0][l[0].Length-1];
    bool f=true;
    for(int i=1;i<s;i++){
      l[i]=Console.ReadLine();
      f=f&&(l[i][0]==l[i-1][l[i-1].Length-1]);
    }
    Console.WriteLine(f&&l.Distinct().Count()==s?"Yes":"No");
  }
}