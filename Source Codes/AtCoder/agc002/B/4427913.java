import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    void run() {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), m = sc.nextInt();
        int[] cnt = new int[n];
        Arrays.fill(cnt, 1);
        Set<Integer> s = new HashSet<>();
        s.add(0);
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt() - 1, y = sc.nextInt() - 1;
            cnt[x]--;
            cnt[y]++;
            if (s.contains(x)) {
                s.add(y);
            }
            if (cnt[x] == 0) {
                s.remove(x);
            }
        }
        debug(s);
        System.out.println(s.size());
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }


    public static void main(String[] args) {
        new Main().run();
    }
}