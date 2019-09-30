import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n, k, min;
      n=Integer.parseInt(sc.next());
      k=Integer.parseInt(sc.next());
      int[] h = new int[n];
      for(int i=0; i<n; i++){
        h[i]=Integer.parseInt(sc.next());
      }

      Arrays.sort(h);
      min=h[k-1]-h[0];
      for(int i=1; i<n-k+1; i++){
        if(h[i+k-1]-h[i]<min){
          min=h[i+k-1]-h[i];
        }
      }

      System.out.println(min);
      
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}