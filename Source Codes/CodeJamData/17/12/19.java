import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main {
    private static StringTokenizer st;
    private static BufferedReader br;
    public static long MOD = 1000000007;
    public static double EPS = 0.000001;

    public static void print(Object x) {
        System.out.println(x + "");
    }
    public static String join(Collection<?> x, String space) {
        if (x.size() == 0) return "";
        StringBuilder sb = new StringBuilder();
        boolean first = true;
        for (Object elt : x) {
            if (first) first = false;
            else sb.append(space);
            sb.append(elt);
        }
        return sb.toString();
    }

    public static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            st = new StringTokenizer(line.trim());
        }
        return st.nextToken();
    }
    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    public static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public static int N;
    public static int P;
    public static int[] recipe;

    public static int solve(List<List<Long>> packets) {
        int servings = 1;
        int minPackets = P;
        int kits = 0;

        while (minPackets > 0) {
            // Eliminate too-small packets
            for (int i = 0; i < N; i++) {
                List<Long> p = packets.get(i);
                while (p.size() > 0 && p.get(0) < 0.9 * servings * recipe[i] - 0.00001) {
                    p.remove(0);
                    minPackets = Math.min(minPackets, p.size());
                }
            }

            // Check packets of correct size
            int valid = 0;
            for (int i = 0; i < N; i++) {
                List<Long> p = packets.get(i);
                if (p.size() > 0 && p.get(0) <= 1.1 * servings * recipe[i] + 0.00001) {
                    valid += 1;
                }
            }

            // If all valid, make a kit
            if (valid == N) {
                for (int i = 0; i < N; i++) {
                    packets.get(i).remove(0);
                }
                minPackets -= 1;
                kits += 1;
            } else {
                // Otherwise, some packets too big, move on
                servings += 1;
            }
        }
        return kits;
    }

    public static void main(String[] args) throws IOException {
        // br = new BufferedReader(new InputStreamReader(System.in));
        br = new BufferedReader(new FileReader("input.txt"));

        int T = nextInt();
        for (int t = 1; t <= T; t++) {
            N = nextInt();
            P = nextInt();
            recipe = new int[N];

            List<List<Long>> packets = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                packets.add(new ArrayList<>());
                recipe[i] = nextInt();
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < P; j++) {
                    packets.get(i).add(nextLong());
                }
                Collections.sort(packets.get(i));
            }

            System.out.printf("Case #%d: %d%n", t, solve(packets));
        }
    }
}
