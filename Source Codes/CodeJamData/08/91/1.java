import java.io.IOException;
import java.io.PrintWriter;
import java.io.File;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

public class AFenwick implements Runnable {
    class Person {
        int a;
        int b;
        int c;

        Person(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    int[][] fh;
    int[][] fv;

    void add(int x, int y) {
        for (int i = y; i <= 10000; i++) {
            fh[x][i]++;
        }
        for (int i = x; i <= 10000; i++) {
            fv[y][i]++;
        }
    }

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter("A-large.out");

        int tn = in.nextInt();
        for (int test = 1;  test <= tn; test++) {
            System.err.println(test);
            int n = in.nextInt();
            Person[] p = new Person[n];
            for (int i = 0; i < n; i++) {
                p[i] = new Person(in.nextInt(), in.nextInt(), in.nextInt());
            }
            Arrays.sort(p, new Comparator<Person>() {
                public int compare(Person o1, Person o2) {
                    return o1.a - o2.a;
                }
            });
            int d = 0;
            int best = 0;
            fh = new int[10001][10001];
            fv = new int[10001][10001];
            for (int a = 0; a <= 10000; a++) {
                if (a % 1000 == 0) System.err.println(a);
                while (d < n && p[d].a <= a) {
                    add(p[d].b, p[d].c);
                    d++;
                }

                int cur = 0;
                cur = fv[0][10000 - a];
                for (int b = 0; b + a < 10000; b++) {
                    if (cur > best) {
                        best = cur;
                    }
                    cur = cur - fh[10000 - a - b][b] + fv[b + 1][10000 - a - b - 1];
                }
                if (cur > best) {
                    best = cur;
                }
            }
            System.out.printf("Case #%d: %d\n", test, best);
            out.printf("Case #%d: %d\n", test, best);
            fh = null;
            fv = null;
            System.gc();

        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static void main(String[] s) {
        new Thread(new AFenwick()).start();
    }
}
