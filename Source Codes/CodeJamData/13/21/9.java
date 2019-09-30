import gcj.GCJ;

import java.util.Arrays;
import java.util.Scanner;

public class Osmos {

    public static void main(String[] args) {
        Scanner s = GCJ.createScanner('A', true);
        int T = s.nextInt();
        for (int i = 1; i <= T; i++) {
            int size = s.nextInt();
            int N = s.nextInt();
            int[] m = new int[N];
            for (int j = 0; j < N; j++) {
                m[j] = s.nextInt();
            }
            Arrays.sort(m);
            int min = N;
            if (size > 1) {
                int cnt = 0;
                for (int j = 0; j < N; j++) {
                    while (size <= m[j]) {
                        cnt++;
                        size += size - 1;
                    }
                    size += m[j];
                    min = Math.min(min, cnt + N - j - 1);
                }
            }
            GCJ.out(i, Integer.toString(min));
        }
    }

}
