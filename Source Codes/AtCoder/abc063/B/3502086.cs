using System;
using System.Collections.Generic;

class Program{
 static void Main(string[] args){
   var str=Console.ReadLine();
   var set=new HashSet<char>();
   var isPri=true;
   for(var i=0;i<str.Length;i++){
     if(set.Contains(str[i])){
      isPri=false;break; 
     }
     set.Add(str[i]);
   }
   Console.WriteLine(isPri?"yes":"no");
 }
}