using System;
class P{
  static void Main(){
    var a=new char[][]{Console.ReadLine().ToCharArray(),Console.ReadLine().ToCharArray()};
   if(a[0].Length>a[1].Length){
     Console.WriteLine("GREATER");
    }else if(a[0].Length<a[1].Length){
      Console.WriteLine("LESS");
    }else{
      for(int i=0;i<a[0].Length;i++){
        if(a[0][i]>a[1][i]){Console.WriteLine("GREATER");return;}
        if(a[0][i]<a[1][i]){Console.WriteLine("LESS");return;}
      }
      Console.WriteLine("EQUAL");
    }
  }
}