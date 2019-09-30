import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        // start?????????(tmp)?????????????????
        int start = 1;
        int end = 1;
        int maxDis = -1;

        for(int j = 0; j < 2; j++) {
            start = end;
            maxDis = -1;
            for (int i = 1; i <= N; i++) {
                System.out.printf("? %d %d\n", start, i);
                int dist = sc.nextInt();

                if (dist > maxDis) {
                    end = i;
                    maxDis = dist;
                }
            }
        }

        out.println("! " + maxDis);
    }
}