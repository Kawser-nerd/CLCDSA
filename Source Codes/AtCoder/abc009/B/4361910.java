import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n, ans;

      n=Integer.parseInt(sc.next());
      int[] a = new int[n];
      for(int i=0; i<n; i++){
        a[i]=Integer.parseInt(sc.next());
      }

      Arrays.sort(a);
      ans=a[n-1];
      for(int i=n-1; i>0; i--){
        if(a[i]>a[i-1]){
          ans=a[i-1];
          break;
        }
      }
      System.out.println(ans);
                
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}