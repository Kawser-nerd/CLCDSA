import java.util.*;
public class Main {
   public static void main(String[] args) {  
      Scanner sc = new Scanner(System.in);
      long n = sc.nextLong();
      long m = sc.nextLong();
      
      long ans = (1900*m + 100*(n-m))*(long)Math.pow(2,m);
      System.out.println(ans);
   }
}