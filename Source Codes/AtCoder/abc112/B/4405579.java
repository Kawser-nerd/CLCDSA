import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n, T;
      n=Integer.parseInt(sc.next());
      T=Integer.parseInt(sc.next());
      int[] c = new int[n];
      int[] t = new int[n];

      for(int i=0; i<n; i++){
        c[i]=Integer.parseInt(sc.next());
        t[i]=Integer.parseInt(sc.next());
      }

      int ans=1001;
      for(int i=0; i<n; i++){
        if(t[i]<=T){
          if(c[i]<ans){
            ans=c[i];
          }
        }
      }

      if(ans==1001){
        System.out.println("TLE");
      }else{
        System.out.println(ans);
      }
      
      
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}