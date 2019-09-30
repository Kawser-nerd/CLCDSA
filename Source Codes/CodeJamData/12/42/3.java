import java.io.*;
import java.util.*;

class B {
    FastScanner in;
    PrintWriter out;
    
    class P {
        int i;
        long r;
        
        long x;
        long y;

        P(int i, long r) {
            this.i = i;
            this.r = r;
        }
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.out.println("Running test " + test);
            
            int N = in.nextInt();
            int W = in.nextInt();
            int L = in.nextInt();
            P[] p = new P[N];
            for (int i = 0; i < N; i++) {
                p[i] = new P(i, in.nextInt());
            }

            Arrays.sort(p, new Comparator<P>() {
                public int compare(P o1, P o2) {
                    return o1.r < o2.r ? 1 : o1.r > o2.r ? -1 : 0;
                }
            });

            Random rnd = new Random(239471112);
            for (int i = 0; i < N; i++) {
                boolean ok = false;
                do {
                    ok = true;
                    p[i].x = rnd.nextInt(W + 1);
                    p[i].y = rnd.nextInt(L + 1);
                    for (int j = 0; j < i; j++) {
                        if ((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y) < (p[i].r + p[j].r) * (p[i].r + p[j].r)) {
                            ok = false;
                            break;
                        }
                    }
                } while (!ok);
            }
            
            Arrays.sort(p, new Comparator<P>() {
                public int compare(P o1, P o2) {
                    return o1.i - o2.i;
                }
            });
            String ans = "";
            for (int i = 0; i < N; i++) {
                ans += " " + p[i].x + " " + p[i].y;
            }
            
            out("Case #%d:%s\n", test, ans);
        }
    }
    
    void out(String s, Object... x) {
        out.printf(s, x);
        System.out.printf(s, x);
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-large.in"));
            out = new PrintWriter(new File("B-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new B().run();
    }
}