import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n;
      
      n=Integer.parseInt(sc.next());
      int[] t = new int[n+1];
      t[0]=0;
      t[1]=0;
      if(n>=2){
        t[2]=0;
        if(n>=3){
          t[3]=1;
          if(n>=4){
            for(int i=4; i<=n; i++){
              t[i]=t[i-1]+t[i-2]+t[i-3];
              if(t[i]>10007){
                t[i]=t[i]%10007;
              }
            }
          }
        }
      }

      System.out.println(t[n]);
      
    }catch (Exception e) {
      System.out.println("out");
    }
  }
}