import java.util.Scanner;

public class Main {
    private static int n;
    private static boolean[][] a;


    private static int solve(int include, int i) {
        if(i == n) {
            int res = 0;
            for(int j = 0; j < n; j++) {
                if(include % 2 == 1) res++;
                include /= 2;
            }
            return res;
        }

        boolean flag = true;
        int tmp = include;
        for(int j = 0; j < i; j++) {
            if(tmp % 2 == 1 && !a[j][i]) {
                flag = false;
                break;
            }
            tmp /= 2;
        }

        if(flag) {
            return Math.max(solve(include + (int) Math.pow(2, i), i + 1), solve(include, i + 1));
        }else {
            return solve(include, i + 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        int m = sc.nextInt();

        a = new boolean[n][n];
        for(int i = 0; i < m; i++) {
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            a[x][y] = true;
        }

        System.out.println(solve(0, 0));

        sc.close();
    }
}