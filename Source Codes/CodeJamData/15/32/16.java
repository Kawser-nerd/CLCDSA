/**
 * Created by wei on 4/11/15.
 */
import java.io.*;
import java.util.*;


public class SolutionB {
    static Scanner scan = new Scanner (System.in);
    static PrintStream out = System.out;


    private static void solve() {
        int K = scan.nextInt(), L = scan.nextInt(), S = scan.nextInt();

        String keys = scan.next();
        String word = scan.next();

        int[] keyCounts = new int[26];
        for (char c : keys.toCharArray()) {
            int k = (int) (c - 'A');
            keyCounts[k]++;
        }

        // Can we have word that overlap. word[0..l1] == word[l2..l].
        int idx = 1;
        while (idx < L) {
            if (word.substring(0, L - idx).equals(word.substring(idx)))
                break;
            ++idx;
        }

        int totalB = (idx == L) ? S/L : (S - L)/idx + 1;
        double percentage = 1;
        for (char c : word.toCharArray()) {
            int k = (int) (c - 'A');
            int cnt = keyCounts[k];

            if (cnt == 0) {
                out.println ("0.0");
                return;
            }

            percentage *= (double)cnt/K;
        }
        out.println (totalB - percentage * (S - L + 1));

    }


    public static void main(String[] args) {
        int T = scan.nextInt();

        for (int i = 1; i <= T; ++i) {
            out.print("Case #" + i + ": ");
            solve();
        }

    }
}
