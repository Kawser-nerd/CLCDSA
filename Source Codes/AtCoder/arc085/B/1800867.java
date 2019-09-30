import java.util.*;
public class Main {
   public static void main(String[] args) {  
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      long z = sc.nextLong();
      long w = sc.nextLong();
      long[] ar = new long[n];
      for(int i = 0; i < n; i++){
         ar[i] = sc.nextLong();
      }
      
      if(n == 1){
         System.out.println(Math.abs(ar[0] - w));
      }
      else {
         long ans = 0;
         for(int i = 1; i < ar.length; i++){
            ans = Math.max(Math.abs(ar[i] - w), Math.abs(ar[i] - ar[i-1]));
         }
         System.out.println(ans);
      } 
   }
}