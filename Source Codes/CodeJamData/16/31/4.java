import java.util.*;

public class A {

    static Scanner in;

    public static void main(String[] args) {
        in = new Scanner(System.in);
        int T = in.nextInt();
        for (int C = 1; C <= T; C++) {
            System.out.println("Case #" + C + ":" + solve());
        }
    }

    public static String solve() {
        String out = "";
        int n = in.nextInt();
        int[] count = new int[n];
        int remaining = 0;
        for (int i = 0; i < n; i++) {
            count[i] = in.nextInt();
            remaining += count[i];
        }

        while(remaining > 0) {
            out += " ";
            int maxIdx = -1;
            for (int i = 0; i < n; i++) {
                if (count[i] > 0 && (maxIdx == -1 || count[i] > count[maxIdx])) {
                    maxIdx = i;
                }
            }
            out += (char) (maxIdx + 'A');
            count[maxIdx]--;
            remaining--;
            if (remaining <= 0) break;
            maxIdx = -1;
            int gT0 = 0;
            boolean tie = false;
            for (int i = 0; i < n; i++) {
                if (count[i] > 0) {
                    gT0 ++;
                }
                if (count[i] > 0 && (maxIdx == -1 || count[i] > count[maxIdx])) {
                    maxIdx = i;
                } else if (count[i] > 0 && gT0 == 2 && count[i] == count[maxIdx]) {
                    tie = true;
                }
            }
            boolean skip = tie && gT0 == 2;
            if (!skip) {
                out += (char) (maxIdx + 'A');
                count[maxIdx]--;
                remaining--;
            }
        }

        return out;
    }
}
