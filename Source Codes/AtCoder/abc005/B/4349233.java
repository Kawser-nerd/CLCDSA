import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n;
      
      n=Integer.parseInt(sc.next());
      int[] t = new int[n];
      for(int i=0; i<n; i++){
        t[i]=Integer.parseInt(sc.next());
      }

      Arrays.sort(t);

      System.out.println(t[0]);
      
    }catch (Exception e) {
      System.out.println("out");
    }
  }
}