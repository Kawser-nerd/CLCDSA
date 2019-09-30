using System;
public class Hello{
    public static void Main(){
      int n=int.Parse(Console.ReadLine());
      int[] a= new int[n];
      var line=Console.ReadLine();
      int ans=0;
      for(int i=0;i<n;i++){
       a[i]=int.Parse(line.Split()[i]); 
      }
      Array.Sort(a);
      Array.Reverse(a);
      for(int i=0;i<n;i++){
        if(i%2==0)ans+=a[i];
        else ans-=a[i];
      }
      
      Console.WriteLine(ans);
    }
}