import java.util.*;
import java.math.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long[] t = new long[n];
    for(int i = 0; i < n; i++){
      t[i] = sc.nextLong();
    }
    long tmp = t[0];
    for(int i = 1; i < n; i++){
      tmp = gcd(tmp, t[i]);
    }
    
    System.out.println(tmp);
  }
  
  public static long gcd(long a, long b){
    long max = Math.max(a, b);
    long min = Math.min(a, b);
    while(max % min != 0){
      max = max % min;
      long tmp = max;
      max = min;
      min = tmp;
    }
    BigInteger bi = new BigInteger(String.valueOf(a));
    bi = bi.multiply(new BigInteger(String.valueOf(b)));
    bi = bi.divide(new BigInteger(String.valueOf(min)));
    String tmp = bi.toString();
    return Long.parseLong(tmp);
  }
}