import java.io.*;
import java.util.*;

public class Factory {

    public void solve() {
        int n = in.nextInt();

        boolean[][] know = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            String s=  in.nextToken();
            for (int j = 0; j < n; j++) {
                know[i][j] = s.charAt(j) == '1';
            }
        }


        int min = Integer.MAX_VALUE;
        for (int mask = 0; mask < (1 << (n * n)); mask++) {
            boolean[][] teach = new boolean[n][n];
            int cost = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    teach[i][j] = ((mask >> (i * n + j)) & 1) == 1;
                    if (teach[i][j] && !know[i][j]) {
                        cost++;
                    }
                    teach[i][j] |= know[i][j];
                }
            }

            if (ok(teach)) {
//                System.err.println(mask);
                min = Math.min(min, cost);
            }
        }
        out.println(min);
    }

    boolean[][] can;
    boolean[] usedPeople, usedMachines;
    int n;

    boolean ok(boolean[][] can) {
        n = can.length;
        usedPeople = new boolean[n];
        usedMachines = new boolean[n];
        this.can = can;
        return go(0);
    }

    boolean go(int pos) {
        if (pos == n) {
            return true;
        }

        for (int person = 0; person < n; person++) {
            if (!usedPeople[person]) {
                boolean canContinue = false;
                for (int machine = 0; machine < n; machine++) {
                    if (!usedMachines[machine] && can[person][machine]) {
                        usedPeople[person] = true;
                        usedMachines[machine] = true;
                        canContinue = true;
                        if (!go(pos + 1)) {
                            return false;
                        }
                        usedPeople[person] = false;
                        usedMachines[machine] = false;
                    }
                }
                if (!canContinue) {
                    return false;
                }
            }
        }
        return true;
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
        new Factory().run();
    }
}
