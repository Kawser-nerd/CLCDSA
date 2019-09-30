import java.io.*;
import java.util.*;

public class B {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    void solve(int test) throws IOException {
        int p = in.nextInt();
        int q = in.nextInt();
        int n = in.nextInt();
        int[] h = new int[n];
        int[] g = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = in.nextInt();
            g[i] = in.nextInt();
        }
        final int MAX = 1000 + 100;
        int[] free = new int[MAX];
        Arrays.fill(free, -1);
        free[1] = 0;
        int[] free2 = new int[MAX];
        for (int monster = 0; monster < n; monster++) {
            int smallestNumberToKill = 1;
            int towerDo = 0;
            int towerAdd = 1 + (h[monster] - 1) / q;
            for (int tower = towerAdd - 1; tower >= 0;) {
                int curH =  h[monster] - tower * q;
                int kill = 1 + (curH - 1) / p;
                smallestNumberToKill = kill;
                towerDo = tower;
                break;
            }
            int cost = smallestNumberToKill > MAX - 1 ? Integer.MAX_VALUE
                    : smallestNumberToKill - towerDo;
            
            Arrays.fill(free2, -1);
            for (int wasFree = 0; wasFree < MAX; wasFree++)
                if (free[wasFree] != -1) {
                    free2[wasFree + towerAdd] = Math.max(free2[wasFree + towerAdd], free[wasFree]);
                    if (wasFree >= cost) {
                        free2[wasFree - cost] = Math.max(free2[wasFree - cost],
                                free[wasFree] + g[monster]);
                    }
                }

            int[] tmp = free;
            free = free2;
            free2 = tmp;
        }
        int max = 0;
        for (int i = 0; i < MAX; i++) {
            max = Math.max(max, free[i]);
        }
        out.println(max);
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("B.in"));
            out = new PrintWriter(new File("B.out"));

            int testNumber = in.nextInt();
            for (int test = 1; test <= testNumber; test++) {
                out.print("Case #" + (test) + ": ");
                solve(test);
                System.out.println(test);
            }

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }


    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }
}