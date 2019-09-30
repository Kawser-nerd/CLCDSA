import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicInteger;

public class A {

    static String[] answers;
    static AtomicInteger ready;

    static class Solver implements Runnable {

        int id;
        int m;
        String s;
        String result;

        Solver(String s, int m, int id) {
            this.s = s;
            this.m = m;
            this.id = id;
        }

        boolean isVowel(char ch) {
            return ch == 'o' || ch == 'a' || ch == 'e' || ch == 'u' || ch == 'i';
        }

        @Override
        public void run() {
            char[] a = s.toCharArray();
            int n = a.length;
            int[] consecutiveConsNext = new int[n + 1];
            consecutiveConsNext[n] = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (isVowel(a[i])) {
                    consecutiveConsNext[i] = 0;
                } else {
                    consecutiveConsNext[i] = consecutiveConsNext[i + 1] + 1;
                }
            }
            int[] nextPosOfAtLeastMConseqCons = new int[n + 1];
            nextPosOfAtLeastMConseqCons[n] = -1;
            for (int i = n - 1; i >= 0; i--) {
                if (consecutiveConsNext[i] >= m) {
                    nextPosOfAtLeastMConseqCons[i] = i;
                } else {
                    nextPosOfAtLeastMConseqCons[i] = nextPosOfAtLeastMConseqCons[i + 1];
                }
            }
            long ans = 0;
            for (int i = 0; i < n; i++) {
                if (nextPosOfAtLeastMConseqCons[i] != -1) {
                    ans += n - nextPosOfAtLeastMConseqCons[i] - m + 1;
                }
            }

            result = "" + ans;
            answers[id] = result;
            ready.incrementAndGet();
            System.err.println(id + " ready " + result);
        }
    }

    void run() throws FileNotFoundException {
        in = new Scanner(new File("input.txt"));
        out = new PrintWriter("output_" + System.currentTimeMillis() + ".txt");
        ready = new AtomicInteger(0);
        int tests = in.nextInt();
        answers = new String[tests];
        Executor e = Executors.newFixedThreadPool(tests);
        for (int i = 0; i < tests; i++) {
            String st = in.next();
            int n = in.nextInt();
            Solver s = new Solver(st, n, i);
            e.execute(s);
        }
        while (ready.get() < tests)
            ;
        for (int i = 0; i < tests; i++) {
            out.println("Case #" + (i+1) + ": " + answers[i]);
        }
        out.close();
        System.exit(0);
    }

    public static void main(String[] args) throws FileNotFoundException {
        new A().run();
    }

    static Scanner in;
    static PrintWriter out;
}
