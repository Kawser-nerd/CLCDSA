import java.io.*;
import java.util.*;

public class CoursesFast {

    static int MAX = 200;
    static double[][] choose = new double[MAX][MAX];
    static {
        for (int i = 0; i < MAX; i++) {
            choose[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
            }
        }
    }

    List<Integer>[] tree;
    char[] letter;
    int n;
    double[] calc;

    double[] calcProb(List<Integer> list) {
        double all = 0;
        double[] pr = new double[list.size()];
        for (int i = 0; i < list.size(); i++) {
            pr[i] = size[list.get(i)];
            all += pr[i];
        }
        for (int i = 0; i < list.size(); i++) {
            pr[i] /= all;
        }
        return pr;
    }

    int[] size;
    void calc(int u) {
        int sz = 0;
        for (int v : tree[u]) {
            calc(v);
            sz += size[v];
        }
        size[u] = sz + 1;
    }

    public void solve() {
        n = in.nextInt();
        tree = new List[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        calc = new double[n];
        Arrays.fill(calc, -1);
        size = new int[n];
        List<Integer> roots=  new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int par = in.nextInt();
            if (par == 0) {
                roots.add(i);
                continue;
            }
            tree[par - 1].add(i);
        }
        for (int i : roots) {
            calc(i);
        }
        letter = in.nextToken().toCharArray();
        int m = in.nextInt();
        String[] words = new String[m];
        for (int i = 0; i < m; i++) {
            words[i] = in.nextToken();
        }
        double[] result = new double[m];
        int ITER = 100000;
        for (int IT = 0; IT < ITER; IT++) {
            Random rng = new Random();
            List<Integer> cur = new ArrayList<>(roots);
            String str = "";

            for (int i = 0; i < n; i++) {
                double[] pr = calcProb(cur);
                double rand = rng.nextDouble();
                int j = 0;
                while (rand >= pr[j]) {
                    rand -= pr[j];
                    j++;
                }

                int course = cur.get(j);
                cur.remove(j);
                cur.addAll(tree[course]);
                str += letter[course];
            }

            for (int i = 0; i < m; i++) {
                if (str.contains(words[i])) {
                    result[i] += 1.0 / ITER;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            out.print(result[i] + " ");
        }
        out.println();
    }


    public void run() {
        try {
            in = new FastScanner("input.txt");
            out = new PrintWriter("output.txt");
            int tests = in.nextInt();
            for (int i = 1; i <= tests; i++) {
                long time = System.currentTimeMillis();
                out.printf("Case #%d: ", i);
                solve();
                System.err.printf("Solved case #%d in %d ms\n", i, System.currentTimeMillis() - time);
            }
            out.close();
        } catch (FileNotFoundException e) {
        }
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new CoursesFast().run();
    }
}
