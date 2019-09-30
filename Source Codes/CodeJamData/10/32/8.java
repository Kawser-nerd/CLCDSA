import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;


public class BB {

  public static long gao(long x, long y, long c) {
    long p = x;
    long t = 0;
    while (p < y) {
      p = p*c;
      t++;
    }
    t--;
    long ret = 0;
    while (t > 0) {
      t /=2;
      ret++;
    }
    return ret;
    
    
  }
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    
    int t = in.nextInt();
    for (int i  = 0; i < t; ++i) {
      long x = in.nextLong();
      long y = in.nextLong();
      long c = in.nextLong();
    
        
        long ret = gao(x, y, c);
        System.out.println("Case #" + (i+1) + ": " + ret);
    }
    
    
    
    
  }
}
