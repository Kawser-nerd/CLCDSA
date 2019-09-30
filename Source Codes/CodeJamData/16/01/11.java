import java.util.*;
import static java.lang.Math.*;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
nextcase:
        for (int t = 1; t <= T; t++) {
            System.out.format("Case #%d: ", t);
            int N = in.nextInt();
            if (N == 0) {
                System.out.format("INSOMNIA\n");
                continue;
            }
            boolean[] seen = new boolean[10];
            for (int i = 1; ; i++) {
                int a = i * N;
                int temp = a;
                while (temp > 0) {
                    seen[temp % 10] = true;
                    temp /= 10;
                }
                boolean all = true;
                for (int j = 0; j < 10; j++) {
                    all &= seen[j];
                }
                if (all) {
                    System.out.format("%d\n", a);
                    continue nextcase;
                }
            }
        }
    }
}
