import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] a = new int[N];

        for(int i = 0; i < N; ++i) {
            a[i] = sc.nextInt();
        }

        long res = Long.MAX_VALUE;
        for(int t = -100; t <= 100; ++t) {
            long s = 0;
            for(int i = 0; i < N; ++i) {
                s += Math.pow(a[i] - t, 2);
            }
            res = Math.min(s, res);
        }
        System.out.println(res);
    }
}