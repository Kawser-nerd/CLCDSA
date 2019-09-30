import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int x = sc.nextInt();

        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }

        long ret = 0;

        for (int i = 1; i < N; i++) {
            long sum = a[i] + a[i-1];

            if (sum <= x) continue;

            long pickNum = Math.min(a[i], sum - x);
            long prevPickNum = Math.max((sum - pickNum) - x, 0);

            ret += pickNum + prevPickNum;

            a[i] -= pickNum;
            a[i-1] -= prevPickNum;
        }

        System.out.println(ret);
    }
}