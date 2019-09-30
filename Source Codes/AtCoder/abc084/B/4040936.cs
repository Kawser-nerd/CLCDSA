using System;
public class Hello{
    public static void Main(){
      var line=Console.ReadLine();
      int a=int.Parse(line.Split()[0]);
      int b=int.Parse(line.Split()[1]);
      string s=Console.ReadLine();
      bool flag=true;
      for(int i=0;i<a;i++){
        bool subflag=false;
        for(char j='0';j<='9';j++){
          if(s[i]==j)subflag=true;
        }
        if(!subflag)flag=false;
      }
      if(s[a]!='-')flag=false;
      for(int i=a+1;i<a+b+1;i++){
        bool subflag=false;
       for(char j='0';j<='9';j++){
        if(s[i]==j)subflag=true; 
       }
        if(!subflag)flag=false;
      }
      if(flag)Console.WriteLine("Yes");
      else Console.WriteLine("No");
    }
}