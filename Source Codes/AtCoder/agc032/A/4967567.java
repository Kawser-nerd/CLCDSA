import java.util.*;

import static java.lang.System.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = ni();

        List<Integer> b = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            b.add(sc.nextInt());
        }

        List<Integer> seq = new ArrayList<>();
        boolean canPick = true;
        while (canPick) {
            canPick = false;
            for (int i = b.size() - 1; i >= 0; i--) {
                if (b.get(i) == i + 1) {
                    b.remove(i);
                    seq.add(i + 1);
                    canPick = true;
                    break;
                }
            }
        }

        if (b.isEmpty()) {
            Collections.reverse(seq);
            for (int s : seq) {
                out.println(s);
            }
        } else {
            out.println(-1);
        }
    }

    static int ni() {
        return sc.nextInt();
    }

    static long nl() {
        return sc.nextLong();
    }

    static String ns() {
        return sc.next();
    }

    static int[] niarr(int N) {
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }
        return a;
    }

    static long[] nlarr(int N) {
        long[] a = new long[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextLong();
        }
        return a;
    }
}