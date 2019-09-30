import java.util.Scanner;

public class Main {

    static Scanner in = new Scanner(System.in);

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        int t = 0;
        boolean f = true;
        for(int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            if(i == 0) t= a[i];
            if(f && t != a[i]) f = false;
        }
        if(f) {
            System.out.println(0);
            return;
        }

        int ans = Integer.MAX_VALUE;
        for(int i = -100; i <= 100; i++) {
            int sum = 0;
            for(int j : a) {
                sum += Math.pow(j - i, 2);
            }
            ans = Math.min(ans, sum);
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}