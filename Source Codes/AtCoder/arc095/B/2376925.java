import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        TreeSet<Integer> set = new TreeSet<>();
        for (int i = 0; i < n; ++i) {
            set.add(sc.nextInt());
        }

        int N = set.last();
        if (set.contains(N / 2)) {
            System.out.printf("%d %d\n", N, N / 2);
            return;
        }

        int rl = set.lower(N / 2);
        int rr = set.higher(N / 2);

        int R = rl >= N - rr ? rl : rr;

        System.out.printf("%d %d\n", N, R);
    }
}