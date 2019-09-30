import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("Main.in"));
        PrintWriter out = new PrintWriter(new File("Main.out"));
        int tests = in.nextInt();
        for (int test = 1; test <= tests; test++) {
            out.print("Case #" + test + ": ");
            int n = in.nextInt();
            int k = in.nextInt();
            int B = in.nextInt();
            int T = in.nextInt();
            int[] x = new int[n];
            int[] v = new int[n];
            for (int i = 0; i < n; i++) x[i] = in.nextInt();
            for (int i = 0; i < n; i++) v[i] = in.nextInt();
            boolean[] can = new boolean[n];
            int z = 0;
            for (int i = 0; i < n; i++) {
                can[i] = x[i] + v[i]*T >= B;
                if (can[i]) z++;
            }
            if (z < k) {
                out.println("IMPOSSIBLE");
                continue;
            }
            int ans = 0;
            z = 0;
            for (int i = n - 1; i >= 0 && k > 0; i--)
                if (can[i]) {
                    ans += z;
                    k--;
                } else z++;
            out.println(ans);
        }
        out.close();
    }
}
