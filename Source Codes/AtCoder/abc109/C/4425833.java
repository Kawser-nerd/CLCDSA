import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n;
      n=Integer.parseInt(sc.next());
      int[] x=new int[n+1];
      for(int i=0; i<n+1; i++){
        x[i]=Integer.parseInt(sc.next());
      }

      Arrays.sort(x);
      int[] y=new int[n];
      for(int i=0; i<n; i++){
        y[i]=x[i+1]-x[i];
      }

      int ans=0;
      for(int i=0; i<n; i++){
        ans=gcd(y[i], ans);
      }

      System.out.println(ans);
    
      }catch (Exception e) {
      System.out.println("out");
    }
  }

  public static int gcd(int m, int n){
    if(m<n){
      return gcd(n,m);
    }   
    if(n==0){
      return m;
    }else{
      return gcd(n, m%n);
    }
    
  }
}