import java.io.PrintStream;
import java.util.Scanner;
public class Main {
    private static final PrintStream ps = System.out;
    private static final Scanner     sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        long sum = 0;
        long ans = 0;
        long xsum = 0;
        int r = 0;
        for (int l = 0; l < n; l++) {
            
            if (l != 0) {
                xsum ^= a[l-1];
                sum -= a[l-1];
            }
            while (true) {
                if (r >= n) {
                    ans += r - l;
                    break;
                }
                xsum ^= a[r];
                sum += a[r];
                
                if (xsum != sum) {
                  ans += r - l;
                  xsum ^= a[r];
                  sum -= a[r];
                  break;
                } 
                r++;
            }
        }
        ps.println(ans);
    }
}