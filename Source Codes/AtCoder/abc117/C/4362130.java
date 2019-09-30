import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n, m;
      n=Integer.parseInt(sc.next());
      m=Integer.parseInt(sc.next());
      int[] x = new int[m];
      for(int i=0; i<m; i++){
        x[i]=Integer.parseInt(sc.next());
      }

      Arrays.sort(x);
      int[] d = new int[m-1];
      for(int i=0; i<m-1; i++){
        d[i]=x[i+1]-x[i];
      }
      Arrays.sort(d);
      int ans=0;
      for(int i=0; i<m-n; i++){
        ans=ans+d[i];
      }
      System.out.println(ans);
                
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}