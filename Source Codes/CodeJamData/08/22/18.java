import java.io.*;
import java.util.*;

/**
 * User: def
 * Date: 26.07.2008
 */
public class B {
    public static void main(String args[]) throws IOException {
        new B().solve();
    }

    void solve() throws IOException {

        Arrays.fill(p, true);
        for(int i = 2; i <= maxp; ++i) {
            if(p[i]) {
                primes.add(i);
                int j = 2 * i;
                while(j <= maxp) {
                    p[j] = false;
                    j += i;
                }
            }
        }

        br = new BufferedReader(new FileReader("B-large.in"));
        pw = new PrintWriter("B-large.out");

        int C = Integer.parseInt(br.readLine());
        for(int c = 1; c <= C; ++c) {
            System.out.println(c);
            StringTokenizer st = new StringTokenizer(br.readLine());
            long A = Long.parseLong(st.nextToken());
            long B = Long.parseLong(st.nextToken());
            long P = Long.parseLong(st.nextToken());

            int n = (int)(B - A + 1);
            for(int i = 0; i < n; ++i) {
                link[i] = i;
                rank[i] = 0;
            }

            for(int i = 0; i < primes.size(); ++i) {
                int d = primes.get(i);
                if(d > n) break;
                if(d >= P) {
                    long k = A / d;
                    long s0 = k * d;
                    if(s0 < A) s0 += d;
                    long s = s0 + d;
                    while(s <= B) {
                        join((int)(s0 - A), (int)(s - A));
                        s += d;
                    }

                }
            }

            set.clear();
            for(int i = 0; i < n; ++i) {
                set.add(getSet(i));
            }

            pw.println("Case #" + c + ": " + set.size());

        }

        pw.close();
    }

    Set<Integer> set = new HashSet<Integer>();
    int getSet(int a) {
        if(a == link[a]) return a;
        int r = getSet(link[a]);
        link[a] = r;
        return r;
    }

    void join(int a, int b) {
        a = getSet(a);
        b = getSet(b);
        if(a != b) {
            if(rank[a] > rank[b]) {
                link[b] = a;
                rank[a] += rank[b];
            } else {
                link[a] = b;
                rank[b] += rank[a];
            }
        }
    }

    int[] link = new int[maxp];
    int[] rank = new int[maxp];


    List<Integer> primes = new ArrayList<Integer>();

    boolean p[] = new boolean[maxp + 1];

    static int maxp = 1000011;

    BufferedReader br;
    PrintWriter pw;
}
