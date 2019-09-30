import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

    private static final long SEED = 142464575786945324L;
    private int size;
    private int nn;
    private static final int SIZE = (1 << 16);
    private long[][] aa;

    public static void main(String[] args) throws FileNotFoundException {

//        System.out.println(500);
//        Random random = new Random();
//        for (int i = 0; i < 500; i++) {
//            System.out.println(Math.abs(random.nextLong()) % 1000000000000L);
//        }

        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            long start = System.currentTimeMillis();
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
            System.out.println((System.currentTimeMillis() - start) / 1000);
        }
        out.close();
    }

    private static final int MAX = 100000000;
    long[] ht = new long[MAX];
    long[] sd = new long[MAX];

    void add(long x, long s) {
        int hash = (int) ((x * 31) % (MAX - 100));
        while (ht[hash] != 0) hash++;
        ht[hash] = x;
        sd[hash] = s;
    }

    long check(long x) {
        int hash = (int) ((x * 31) % (MAX - 100));
        while (ht[hash] != 0) {
            if (ht[hash] == x) return sd[hash];
            hash++;
        }
        return 0;
    }


    private String solve(Scanner in) {
        n = in.nextInt();
        a = new long[n + 16];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextLong();
        }
        nn = (n + 15) / 16;
        aa = new long[nn][SIZE];
        for (int i = 0; i < nn; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 16; k++) {
                    if (((j >> k) & 1) > 0) {
                        aa[i][j] += a[i * 16 + k];
                    }
                }
            }
        }

        z = new int[nn];
        while (true) {
            long ss = seed;
            long sum = next();
            if (sum == 0) continue;
            long s = check(sum);
            if (s > 0) {
                long oldseed = seed;
                seed = s;
                int[] zz = z.clone();
                if (next() != sum) {
                    throw new RuntimeException();
                }
                boolean ok = false;
                for (int i = 0; i < nn - 1; i++) {
                    if (zz[i] != z[i]) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    boolean[] zzz1 = new boolean[n + 16];
                    boolean[] zzz2 = new boolean[n + 16];
                    for (int i = 0; i < nn; i++) {
                        for (int k = 0; k < 16; k++) {
                            zzz1[i * 16 + k] =
                                    (((z[i] >> k) & 1) > 0);
                            zzz2[i * 16 + k] =
                                    (((zz[i] >> k) & 1) > 0);
                            if (zzz1[i * 16 + k] && zzz2[i * 16 + k]) {
                                zzz1[i * 16 + k] = false;
                                zzz2[i * 16 + k] = false;
                            }
                        }
                    }
                    String res = "\n";
                    long s1 = 0;
                    for (int i = 0; i < n; i++) {
                        if (zzz1[i]) {
                            res += a[i] + " ";
                            s1 += a[i];
                        }
                    }
                    res += "\n";
                    long s2 = 0;
                    for (int i = 0; i < n; i++) {
                        if (zzz2[i]) {
                            res += a[i] + " ";
                            s2 += a[i];
                        }
                    }
                    System.out.println(s1 + " " + s2);
                    if (s1 != s2) throw new RuntimeException();
                    return res;
                } else {
                    seed = oldseed;
                }
            } else {
                add(sum, ss);
                size++;
                if (size % 1000000 == 0) {
                    System.out.println(size);
                }
            }
        }
    }

    int n;
    int[] z;
    long[] a;

    private long next() {
        long res = 0;
        for (int i = 0; i < nn; i++) {
            z[i] = nextWord();
            res += aa[i][z[i]];
        }
        return res;
    }

    private int nextWord() {
        seed = seed * 31 + SEED;
        return (int) ((seed >> (64 - 16)) & (SIZE - 1));
    }

    long seed;

    boolean nextBoolean() {
        seed = seed * 31 + SEED;
        return seed > 0;
    }
}