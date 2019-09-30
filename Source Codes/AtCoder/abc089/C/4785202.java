import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        long[] startNum = new long['Z' - 'A' + 1];
        for (int i = 0; i < N; i++) {
            String str = sc.next();
            startNum[str.charAt(0) - 'A']++;
        }

        long comb = 0;
        char[] march = new char[]{'M', 'A', 'R', 'C', 'H' };

        for (int i = 0; i < march.length; i++) {
            for (int j = i + 1; j < march.length; j++) {
                for (int k = j + 1; k < march.length; k++) {
                    comb += startNum[march[i] - 'A'] * startNum[march[j] - 'A'] * startNum[march[k] - 'A'];
                }
            }
        }
        out.println(comb);
    }
}