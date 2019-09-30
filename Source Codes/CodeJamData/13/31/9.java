import java.io.*;
import java.util.*;

public class A {

    static class Assert {
        static void check(boolean e) {
            if (!e) {
                throw new Error();
            }
        }
    }

    Scanner in;
    PrintWriter out;

    boolean isCons(char c) {
        return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
    }

    int getPos(String word, int n, int from) {
        int count = 0;
        for (int i = from; i < word.length(); i++) {
            if (isCons(word.charAt(i))) {
                count++;
                if (count == n) {
                    return i;
                }
            } else {
                count = 0;
            }
        }
        return -1;
    }

    long solveOne(String word, int n) {
        long count = 0;
        int pos = getPos(word, n, 0);
        if (pos == -1) {
            return count;
        }
        count += word.length() - pos;
        for (int start = 1; start < word.length(); start++) {
            if (pos - start + 1 >= n) {
                // OK
            } else {
                Assert.check(pos - start + 1 == n - 1);
                if (pos == word.length() - 1) {
                    return count;
                }
                if (isCons(word.charAt(pos + 1))) {
                    pos++;
                } else {
                    pos = getPos(word, n, pos + 2);
                    if (pos == -1) {
                        return count;
                    }
                }
            }
            count += word.length() - pos;
        }
        return count;
    }

    void solve() {
        int nTests = in.nextInt();
        for (int i = 1; i <= nTests; i++) {
            out.printf("Case #%d: %d%n", i, solveOne(in.next(), in.nextInt()));
        }
    }

    void run() {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);
        try {
            solve();
        } finally {
            out.close();
        }
    }

    public static void main(String args[]) {
        new A().run();
    }
}
