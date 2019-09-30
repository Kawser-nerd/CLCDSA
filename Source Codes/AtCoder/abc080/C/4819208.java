import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] f = new int[n][10];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                f[i][j] = sc.nextInt();
            }
        }
        int[][] p = new int[n][11];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 11; j++) {
                p[i][j] = sc.nextInt();
            }
        }
        long ans = Long.MIN_VALUE;
        for (int i = 1; i < 1<<10; i++) {
            int[] c = new int[n];
            for (int j = 0; j < 10; j++) {
                if((i >> j & 1) == 1){
                    for (int k = 0; k < n; k++) {
                        if(f[k][j] == 1) c[k]++;
                    }
                }
            }
            long tmp = 0;
            for(int l = 0; l < n; l++) tmp += p[l][c[l]];
            ans = Math.max(ans, tmp);
        }

        System.out.println(ans);
        sc.close();

    }

}