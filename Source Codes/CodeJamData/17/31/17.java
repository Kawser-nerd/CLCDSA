import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by Eldar on 4/7/2017.
 */
public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new File("output.txt"));

        int T = in.nextInt();
        for(int t = 1; t <= T; t++) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] r = new int[n];
            int[] h = new int[n];
            for(int i = 0; i < n; i++) {
                r[i] = in.nextInt();
                h[i] = in.nextInt();
            }
            for(int i = 0; i < n; i++) {
                for (int j = i - 1; j >= 0; j--) {
                    if (r[j] < r[j + 1]) {
                        int x = r[j];
                        r[j] = r[j + 1];
                        r[j + 1] = x;
                        x = h[j];
                        h[j] = h[j + 1];
                        h[j + 1] = x;
                    }
                }
            }
            double[][] ans = new double[n + 1][k + 1];
            for(int i = 0; i < n; i++) {
                for (int j = 0; j <= k; j++) {
                    ans[i + 1][j] = Math.max(ans[i + 1][j], ans[i][j]);
                    if (j == k) continue;
                    ans[i + 1][j + 1] = Math.max(ans[i + 1][j + 1], ans[i][j] + 2 * Math.PI * r[i] * h[i] + (j == 0 ? Math.PI * r[i] * r[i] : 0));
                }
            }
            out.println("Case #" + t + ": " + ans[n][k]);
        }
        out.close();
    }

    static String solve(String s) {
        if (s.isEmpty()) {
            return "";
        }
        for(int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < s.charAt(0)) {
                return String.valueOf((char)(s.charAt(0) - 1)) + nines(s.length() - 1);
            }
            if (s.charAt(i) > s.charAt(0)) {
                break;
            }
        }
        return s.charAt(0) + solve(s.substring(1));
    }

    static String nines(int length) {
        String ret = "";
        while(length-- > 0) {
            ret += "9";
        }
        return ret;
    }
}
