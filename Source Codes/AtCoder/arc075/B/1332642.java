import java.util.Scanner;
import java.util.Arrays;

public class Main{
  static int n;
  static long a, b;
  static long[] h;
  static final boolean DEBUG = false;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();
    a = sc.nextInt();
    b = sc.nextInt();
    h = new long[n];
    for(int i = 0; i < n; i++){
      h[i] = sc.nextInt();
    }

    long low = 0, high = Integer.MAX_VALUE / 2;
    while(high - low > 1){
      long mid = (low + high) / 2;
      if(f(mid)){
        high = mid;
      }
      else{
        low = mid;
      }
    }

    System.out.println(high);
  }

  private static boolean f(long c){
    long count = 0;
    for(int i = 0; i < n; i++){
      if(h[i] - c * b > 0){
        count += (long)Math.ceil((double)((h[i] - c * b)) / (a - b));
      }
    }
    if(DEBUG){
      System.out.println("count = " + count);
    }
    return count <= c;
  }
}