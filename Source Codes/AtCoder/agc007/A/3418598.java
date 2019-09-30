import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        String[] A = new String[H];
        char[][] a = new char[H][W];
        for (int i = 0; i < H; i++) {
            A[i] = sc.next();
        }
        for (int i = 0; i < H; i++) {
            a[i] = A[i].toCharArray();
        }
        int c=0;
        for (int i = 0; i < H ; i++) {
            for (int j = 0; j < W; j++) {
                if (a[i][j] == '#') {
                    c++;
                }
            }
        }
        System.out.println(c==H+W-1?"Possible":"Impossible");
    }
}