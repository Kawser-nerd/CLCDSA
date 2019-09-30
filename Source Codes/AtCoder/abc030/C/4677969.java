import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        long x = sc.nextLong();
        long y = sc.nextLong();

        long[] as = new long[N];
        long[] bs = new long[M];

        for (int i = 0; i < N; i++) {
            as[i] = sc.nextLong();
        }
        for (int i = 0; i < M; i++) {
            bs[i] = sc.nextLong();
        }

        int count = 0;
        int i = 0;
        while (true) {
            if (i >= as.length) {
                break;
            }
            int index = Arrays.binarySearch(bs, as[i] + x);

            index = (index >= 0) ? index : ~index;
            if (index >= bs.length) {
                break;
            }
            i = Arrays.binarySearch(as, bs[index] + y);
            i = (i >= 0) ? i : ~i;
            count++;
        }
        System.out.println(count);
    }
}