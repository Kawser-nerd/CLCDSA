using System;
public class Hello{
    public static void Main(){
      var n=0;
      int ans=1;
      n=int.Parse(Console.ReadLine());
      int[] d=new int[n];
      for(int i=0;i<n;i++){
        d[i]=int.Parse(Console.ReadLine());
      }
      Array.Sort(d);
      int newsize=d[0];
      for(int i=0;i<n;i++){
        if(newsize<d[i]){
          ans++;
          newsize=d[i];
        }
      }
      Console.WriteLine(ans);
    }
}