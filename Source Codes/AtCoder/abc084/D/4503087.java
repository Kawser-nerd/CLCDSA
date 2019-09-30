import java.util.*;
public class Main {
    static boolean[] f = new boolean[100001];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        List<Integer> l = new ArrayList<>();
        List<Integer> r = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            int left = sc.nextInt();
            int right = sc.nextInt();
            l.add(left);
            r.add(right);
        }
        isPrime();

        int[] cnt = new int[100002];
        for (int i = 3; i <= 100000; i++) {
            if (!f[i] && !f[(i + 1) / 2]) {
                cnt[i] = cnt[i - 1] + 1;
            } else {
                cnt[i] = cnt[i - 1];
            }
        }

        for (int i = 0; i < q; i++) {
            int ans = cnt[r.get(i)] - cnt[l.get(i) - 1];
            System.out.println(ans);
        }
    }
    public static void isPrime() {
        for (int i = 2; i <= 100000; i++) {
            if (!f[i]) {
                for (int j = i + i; j <= 100000; j += i) {
                    f[j] = true;
                }
            }
        }
    }
}