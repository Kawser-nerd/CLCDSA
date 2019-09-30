using System;
using System.Linq;
class P{
  static void Main(){
    var n=Console.ReadLine().Split().Select(int.Parse).ToArray();
    var s=new char[n[0]][];
    for(int i=0;i<n[0];i++)s[i]=Console.ReadLine().ToCharArray();
    for(int i=0;i<n[0];i++){
      if(s[i].Any(x=>x!='.')){
        for(int g=0;g<n[1];g++){
          bool b=false;
          for(int f=0;f<n[0];f++)b=b|(s[f][g]=='#');
          if(b)Console.Write(s[i][g]);
        }
      Console.Write("\n");
      } 
    }
  }
}