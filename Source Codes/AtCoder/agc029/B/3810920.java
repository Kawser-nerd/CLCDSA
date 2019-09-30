import java.util.*;

public class Main {
    static int left(int x) {
        int i = 1;
        while(i <= x) {
            i <<= 1;
        }
        return i - x;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n + 11];
        int[] used = new int[n + 11];
        Map<Integer, Integer> cnt = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            used[i] = 0;
            if (cnt.containsKey(a[i])) {
                cnt.put(a[i], cnt.get(a[i]) + 1);
            } else {
                cnt.put(a[i], 1);
            }
        }
        Arrays.sort(a, 0, n);
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            int x = a[i];
            if (cnt.get(x) == 0) {
                continue;
            }
            cnt.put(x, cnt.get(x) - 1);
            int match = left(x);
            // System.out.println(x);
            // System.out.println(match);
            if (cnt.containsKey(match) && cnt.get(match) > 0) {
                ans += 1;
                cnt.put(match, cnt.get(match) - 1);
            }
        }
        System.out.println(ans);
    }
}