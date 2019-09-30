import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n, ans=0;

      n=Integer.parseInt(sc.next());
      int[] a = new int[n];
      for(int i=0; i<n; i++){
        a[i]=Integer.parseInt(sc.next());
        if(a[i]==2 || a[i]==4 || a[i]==8){
          ans++;
        }else if(a[i]==5){
          ans=ans+2;
        }else if(a[i]==6){
          ans=ans+3;
        }
      }
      
      System.out.println(ans);
                
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}