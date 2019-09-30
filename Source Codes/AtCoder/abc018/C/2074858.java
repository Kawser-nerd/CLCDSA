import java.util.Scanner;

public class Main {

    private static int R,C,K;
    private static String[] SRC;
    private static int L;
    private static int[][] MEM;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        R = sc.nextInt();
        C = sc.nextInt();
        K = sc.nextInt();
        SRC = new String[R];
        for(int i = 0; i < R; i++) {
            SRC[i] = sc.next();
        }
        L = 2*K - 1;
        MEM = new int[R][C];
        for (int i = 0; i < R; i++) {
            if (SRC[i].charAt(C-1) == 'o') {
                MEM[i][C-1] = 1;
            }
            for (int j = C-2; j >= 0; j--) {
                if(SRC[i].charAt(j) == 'o') {
                    MEM[i][j] = MEM[i][j+1] + 1;
                } else {
                    MEM[i][j] = 0;
                }
            }
        }

        int ans = 0;
        for(int i = K-1; i < R-(K-1); i++) {
            for(int j = 0; j < C-L+1; j++) {
                if(ok(i,j)) ans += 1;
            }
        }
        System.out.println(ans);
    }

    private static boolean ok(int y, int x) {
        if (MEM[y][x] < L) return false;
        for (int k = 0; k < K; k++) {
            if (MEM[y-k][x+k] < L-2*k) return false;
            if (MEM[y+k][x+k] < L-2*k) return false;
        }
        return true;
    }

}