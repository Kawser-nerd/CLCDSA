import java.util.*;
import java.util.stream.*;
 
public class Main {
    private static Scanner scanner = new Scanner(System.in);
 
    public static void main(String[]$) {
        int n = scanner.nextInt(), m = scanner.nextInt(), a[] = new int[m], b[] = new int[m], num[] = new int[n + 1];
        long[] ans = new long[m];
        fa = IntStream.rangeClosed(0, n).toArray();
        for (int i = 0; i < m; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
        }
        Arrays.fill(num, 1);
        ans[m - 1] = (long)n * (n - 1) / 2;
        for (int i = m - 1; i > 0; i--) {
            ans[i - 1] = ans[i];
            if (fd(a[i]) != fd(b[i])) {
                ans[i - 1] -= num[fa[a[i]]] * num[fa[b[i]]];
                num[fa[b[i]]] += num[fa[a[i]]];
                fa[fa[a[i]]] = fa[b[i]];
            }
        }
        Arrays.stream(ans).forEach(System.out::println);
    }
 
    static int[] fa;
    static int fd(int a) {
        return fa[a] == a ? a : (fa[a] = fd(fa[a]));
    }
}