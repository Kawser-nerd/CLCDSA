import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    public static void main(String[] $) {
        int n = sc.nextInt(), q = sc.nextInt();
        String s = sc.next();
        int[] AC = new int[n + 1];
        for (int i = 1; i < n; i++) {
            if (s.charAt(i - 1) == 'A' && s.charAt(i) == 'C') {
                AC[i] = 1;
            }
        }
        for (int i = 1; i < n + 1; i++) {
            AC[i] += AC[i - 1];
        }
        for (int i = 0; i < q; i++) {
            int l = sc.nextInt(), r = sc.nextInt();
            int k = 0;
            if (r < n && s.charAt(r - 1) == 'A' && s.charAt(r) == 'C') k++;

            out.println(max(0, AC[r] - AC[l - 1] - k));
        }
        out.close();
    }
}