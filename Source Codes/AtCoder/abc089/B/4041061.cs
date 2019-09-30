using System;
public class Hello{
    public static void Main(){
      int n=int.Parse(Console.ReadLine());
      char[] s = new char[n];
      var line = Console.ReadLine();
      for(int i=0;i<n;i++){
       s[i]=char.Parse(line.Split()[i]); 
      }
      int ans=0;
      bool[] flag = new bool[4];
      for(int i=0;i<n;i++){
        if(s[i]=='P')flag[0]=true;
        else if(s[i]=='W')flag[1]=true;
        else if(s[i]=='G')flag[2]=true;
        else flag[3]=true;
      }
      for(int i=0;i<4;i++){
       if(flag[i])ans++; 
      }
      if(ans==3){
       Console.WriteLine("Three"); 
      }
      else Console.WriteLine("Four");
    }
}