import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }

        int[] rate = new int[]{400, 800, 1200, 1600, 2000, 2400, 2800, 3200};
        boolean[] exist = new boolean[8];
        int master = 0; //3200?????

        for (int i = 0; i < N; i++) {
            if (a[i] >= 3200) {
                master++;
                continue;
            }

            for (int j = 0; j < rate.length; j++) {
                if (a[i] < rate[j]) {
                    exist[j] = true;
                    break;
                }
            }
        }

        int min = 0;
        for (int i = 0; i < exist.length; i++) {
            if (exist[i]) {
                min++;
            }
        }
        int max = min + master;

        if (min == 0) { //??master
            min = 1;
        }

        out.print(min + " " + max);
    }
}