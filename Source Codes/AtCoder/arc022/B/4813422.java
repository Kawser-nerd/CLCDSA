import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        Set<Integer> s = new HashSet<>();
        long ans = syakutori(a, n, s);
        System.out.println(ans);
    }
    public static long syakutori(int[] a, int n, Set<Integer> s) {
        int right = 0;
        long res = 0;
        long sum = 0;
        for (int left = 0; left < n; left++) {
            while (right < n && !s.contains(a[right])) {
                s.add(a[right]);
                right++;
            }
            res = Math.max(res, right - left);
            if (left >= right) {
                right++;
                continue;
            }
            s.remove(a[left]);
        }
        return res;
    }
}