import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;


public class AA {

  public static long gao(int[] a, int [] b) {
    int n = a.length;
    long t = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j)  {
        if ((a[i] - a[j]) * (b[i] - b[j]) < 0) t++;
      }
    }
    return t;
  }
  public static void main(String[] args) throws Exception {
    
    //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    Scanner in = new Scanner(System.in);
    
    int t = in.nextInt();
    for (int i  = 0; i < t; ++i) {
      int n = in.nextInt();
      int[] a = new int[n];
      int[] b = new int[n];
      
      for (int j = 0; j < n; ++j) {
        a[j] = in.nextInt();
        b[j] = in.nextInt();
      }
      
      long ret = gao(a, b);
      System.out.println("Case #" + (i+1) + ": " + ret);
    }
    
    
    
    
  }
}
