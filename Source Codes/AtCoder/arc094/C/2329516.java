import java.util.Scanner;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        int[] b = new int[N];
        int ans = Integer.MAX_VALUE;
        boolean check = true;
        long num = 0;
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            if (a[i] > b[i] && b[i] < ans) {
                check = false;
                ans = b[i];
            }
            num += a[i];
        }
        if (check) {
            System.out.println("0");
            return;
        }
        System.out.println(num - ans);
    }
}