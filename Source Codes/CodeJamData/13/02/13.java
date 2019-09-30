// author: misof
// language: java
import java.util.Scanner;

public class B2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t=1; t<=T; ++t) {
            int R = sc.nextInt();
            int C = sc.nextInt();
            int[][] A = new int[R][C];
            for (int r=0; r<R; ++r) for (int c=0; c<C; ++c) A[r][c] = sc.nextInt();
            int[][] H = new int[R][C];
            for (int r=0; r<R; ++r) for (int c=0; c<C; ++c) H[r][c] = 100;
            for (int r=0; r<R; ++r) {
                int m = 0;
                for (int c=0; c<C; ++c) m = Math.max(m,A[r][c]);
                for (int c=0; c<C; ++c) H[r][c] = Math.min(H[r][c],m);
            }
            for (int c=0; c<C; ++c) {
                int m = 0;
                for (int r=0; r<R; ++r) m = Math.max(m,A[r][c]);
                for (int r=0; r<R; ++r) H[r][c] = Math.min(H[r][c],m);
            }
            boolean ok = true;
            for (int r=0; r<R; ++r) for (int c=0; c<C; ++c) if (A[r][c] != H[r][c]) ok = false;
            System.out.print("Case #"+t+": ");
            if (ok) System.out.println("YES"); else System.out.println("NO");
        }
    }
}
