import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n, m, X, Y;
      n=Integer.parseInt(sc.next());
      m=Integer.parseInt(sc.next());
      X=Integer.parseInt(sc.next());
      Y=Integer.parseInt(sc.next());
      int[] x=new int[n], y=new int[m];
      for(int i=0; i<n; i++){
        x[i]=Integer.parseInt(sc.next());
      }
      for(int i=0; i<m; i++){
        y[i]=Integer.parseInt(sc.next());
      }

      Arrays.sort(x);
      Arrays.sort(y);
      if(Math.max(X, x[n-1])<Math.min(Y, y[0])){
        System.out.println("No War");
      }else{
        System.out.println("War");
      }
      
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}