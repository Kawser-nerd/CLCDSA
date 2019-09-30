import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int x = sc.nextInt();
 
        if (x == 1 || x == 2 * N - 1) {
            out.println("No");
            out.flush();
            return;
        }
 
        out.println("Yes");
        if (N == 2) {
            for (int i = 1, n = 2 * N; i < n; ++i) {
                out.println(i);
            }
        } else {
            if (x > N) {
                for (int i = N; i < N * 2; ++i) {
                    if (i != x) {
                        out.println(i);
                    }
                }
                out.println(x);
                for (int i = 1; i < N; ++i) {
                    if (i != x) {
                        out.println(i);
                    }
                }
            } else {
                for (int i = N + 1; i < N * 2; ++i) {
                    if (i != x) {
                        out.println(i);
                    }
                }
                out.println(x);
                for (int i = 1; i < N + 1; ++i) {
                    if (i != x) {
                        out.println(i);
                    }
                }
            }
        }
        out.flush();
    }
}