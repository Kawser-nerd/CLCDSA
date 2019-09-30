using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var s = string.Join("", Console.ReadLine().Reverse());
    var t = string.Join("", Console.ReadLine().Reverse());
    var a = "";
    var can = false;
    for(var i=0; i<s.Length-t.Length+1; i++){
      for(var j=0; j<t.Length; j++){
        if(t[j]==s[j+i]||s[j+i]=='?'){
          can = true;
        }else{
          //Console.WriteLine("FALSE i={0} j={1}", i, j);
          can = false;
          break;
        }
      }
      if(can){
        //Console.WriteLine("i={0} t.len={1} s.len={2}", i, t.Length, s.Length);
        a = s.Substring(0,i)+t+s.Substring(i+t.Length, s.Length-t.Length-i);
        break;
      }
    }
    Console.WriteLine(can?string.Join("", a.Replace('?', 'a').Reverse()):"UNRESTORABLE");
  }
}