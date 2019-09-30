using System;
class P{
  static void Main(){
    var s=Console.ReadLine().ToCharArray();
    long a=0;
    for(int i=0;i<s.Length;i++)if(s[i]=='A'){a=i;break;}
    for(int i=s.Length-1;i>=0;i--)if(s[i]=='Z'){a=i-a+1;break;}
   Console.WriteLine(a);
  }
}