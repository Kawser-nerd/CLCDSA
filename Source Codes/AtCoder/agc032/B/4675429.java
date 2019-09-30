import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner sc = new Scanner(System.in);
    static final PrintStream so = System.out;
    public static void main(String[] args) {
        int N = sc.nextInt();
        if (N == 3) {
            so.println("2");
            so.println("1 3");
            so.println("2 3");
            return;
        }
        boolean[][] g = new boolean[N + 1][N + 1];
        if (N % 2 == 0) {
            f(g, N);
        } else {
            f(g, N-1);
            for (int i = 1; i < N; i++) {
                g[i][N] = true;
            }
        }
        
        so.println(count(g, N));
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (g[i][j]) {
                    so.println(i + " " + j);
                }
            }
        }
    }
    
    public static int count(boolean[][] g, int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (g[i][j]) count++;
            }
        }
        return count;
    }
    
    public static void f(boolean[][] g, int N) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i != j && i+j != N+1 && !g[j][i]) {
                    g[i][j] = true;
                }
            }
        }
    }
    
    static int  nint()   { return sc.nextInt(); }
    static long nlong()  { return sc.nextLong(); }
    static String next() { return sc.next(); }
    static int[] nints(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = nint();
        return a;
    }
}