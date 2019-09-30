import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int D1, D2;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        D1 = sc.nextInt();
        D2 = sc.nextInt();

        PrintWriter pw = new PrintWriter(System.out);
        for (Cord c : solve()) {
            pw.println(c.x + " " + c.y);
        }
        pw.flush();
    }

    static List<Cord> solve() {
        int[][] d1 = calc(D1);
//        for (int[] arr : d1) {
//            System.out.println( Arrays.toString(arr) );
//        }
//        System.out.println();
        int[][] d2 = calc(D2);
//        for (int[] arr : d2) {
//            System.out.println( Arrays.toString(arr) );
//        }

        List<Cord> answer = new ArrayList<>(N*N);
        for (int i = 0; i < 2 * N; i++) {
            for (int j = 0; j < 2 * N; j++) {
                if( d1[i][j] == 1 && d2[i][j] == 1 ) {
                    answer.add( new Cord(i, j) );
                    if( answer.size() == N*N ) return answer;
                }
            }
        }
        throw new IllegalArgumentException("wtf : " + answer.size());
    }

    static int[][] calc(int d) {
        int[][] area = new int[N*2][N*2];
        List<Cord> ms = calcMove(d);
//        for (Cord m : ms) {
//            System.out.println( "Move(" + m.x + " " + m.y + ")");
//        }
        ArrayDeque<State> q = new ArrayDeque<>();

        for (int i = 0; i < N * 2; i++) {
            for (int j = 0; j < N * 2; j++) {
                if( area[i][j] == 0 ) {
                    run(i, j, area, ms, q);
                }
            }
        }
        return area;
    }

    static class State {
        int x, y;
        int flag;

        public State(int x, int y, int flag) {
            this.x = x;
            this.y = y;
            this.flag = flag;
        }
    }

    static int[] DX = {1, 1, -1, -1};
    static int[] DY = {1, -1, 1, -1};

    static void run(int sx, int sy, int[][] area, List<Cord> ms, ArrayDeque<State> q) {
        area[sx][sy] = 1;
        q.add( new State(sx, sy, 1) );

        while(!q.isEmpty()) {
            State s = q.poll();

            for (Cord m : ms) {
                for (int i = 0; i < 4; i++) {
                    int nflag = -s.flag;
                    int nx = s.x + (m.x * DX[i]);
                    int ny = s.y + (m.y * DY[i]);

                    if( inArea(nx) && inArea(ny) && area[nx][ny] == 0 ) {
                        q.add( new State(nx, ny, nflag) );
                        area[nx][ny] = nflag;
                    }
                }
            }
        }
    }

    static boolean inArea(int i) {
        return 0 <= i && i < N*2;
    }

    static List<Cord> calcMove(int d) {
        // x^2 + y^2 = d
        List<Cord> ms = new ArrayList<>();
        int rd = (int)Math.sqrt(d);
        for (int x = 0; x <= rd; x++) {
            int yy = d - x*x;
            int y = (int)Math.sqrt(yy);
            if( y * y == yy ) {
                ms.add( new Cord(x, y) );
            }
        }
        return ms;
    }

    static class Cord {
        int x, y;

        public Cord(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}