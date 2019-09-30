import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class Main {

    boolean validateMap(char[][] map, int expectedWhite, int expectedBalck) {
        boolean[][] visited = new boolean[map.length][map[0].length];
        int white = 0;
        int black = 0;
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length; j++) {
                if (!visited[i][j]) {
                    if (map[i][j] == '.') {
                        white++;
                    } else {
                        black++;
                    }
                    visit(map, i, j, visited, map[i][j]);
                }
            }
        }
        if (white != expectedWhite) {
            out.println("Excepted white: " + expectedWhite + " Actual: " + white);
        }
        if (black != expectedBalck) {
            out.println("Excepted black: " + expectedBalck + " Actual: " + black);
        }
        if (white != expectedWhite || black != expectedBalck) return false;
        return true;
    }

    private void visit(char[][] map, int i, int j, boolean[][] visited, char c) {
        if (visited[i][j]) return;
        visited[i][j] = true;
        if (i > 0 && !visited[i - 1][j] && map[i - 1][j] == c) {
            visit(map, i - 1, j, visited, c);
        }
        if (i < map.length - 1 && !visited[i + 1][j] && map[i + 1][j] == c) {
            visit(map, i + 1, j, visited, c);
        }
        if (j > 0 && !visited[i][j - 1] && map[i][j - 1] == c) {
            visit(map, i, j - 1, visited, c);
        }
        if (j < map[0].length - 1 && !visited[i][j + 1] && map[i][j + 1] == c) {
            visit(map, i, j + 1, visited, c);
        }
    }

    char[][] getMap(int a, int b) {
        char[][] map = new char[50][50];
        char print;
        if (a <= b) {
            fill(map, '.');
            a--;
            print = '#';
            int tmp = a;
            a = b;
            b = tmp;
        } else {
            fill(map, '#');
            b--;
            print = '.';
        }

        draw(map, a, print);
        int ruined = drawLeftover(map, b, print);
        if (ruined > 0) {
            drawRuined(map, ruined, print);
        }
        return map;
    }

    void solve() {
//        for (int i = 1; i <= 100; i++) {
//            for (int j = 1; j <= 100; j++) {
//                char[][] map = getMap(i, j);
//                boolean validated = validateMap(map, i, j);
//                if (!validated) {
//                    out.println("Error for test: " + i + " " + j);
//                    print(map);
//                    return;
//                }
//            }
//        }


        int a = in.nextInt();
        int b = in.nextInt();
        char[][] map = new char[100][100];
        char print;
        if (a <= b) {
            fill(map, '.');
            a--;
            print = '#';
            int tmp = a;
            a = b;
            b = tmp;
        } else {
            fill(map, '#');
            b--;
            print = '.';
        }

        draw(map, a, print);
        int ruined = drawLeftover(map, b, print);
        if (ruined > 0) {
            drawRuined(map, ruined, print);
        }
        out.print(100 + " ");
        out.print(100 + " ");
        out.println();
        print(map);
    }

    private void drawRuined(char[][] map, int ruined, char print) {
        int start = 1;
        for (int i = map.length - 1; ruined > 0; i -= 2) {
            for (int j = start; j < map.length && ruined > 0; j += 2) {
                map[i][j] = print;
                ruined--;
            }
            start = start == 1 ? 0 : 1;
        }

    }

    private void print(char[][] map) {
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length; j++) {
                out.print(map[i][j]);
            }
            out.println();
        }
    }

    private int drawLeftover(char[][] map, int b, char print) {
        int start = 0;
        int ruined = 0;
        for (int i = 1; b > 0; i += 2) {
            for (int j = start; j < map.length && b > 0; j += 2) {
                map[i][j] = print;
                b--;
                if (!joined(map, i, j, print)) {
                    ruined += join(map, i, j, print);
                }
            }
            start = start == 1 ? 0 : 1;
        }
        return ruined;
    }

    private int join(char[][] map, int i, int j, char print) {
        if (i == 1) {
            map[i][j + 1] = print;
            return 0;
        }
        map[i - 1][j] = print;
        if (j == map.length - 1 || j == 0) {
            return 0;
        }
        return 1;
    }

    private boolean joined(char[][] map, int i, int j, char print) {
        return map[i + 1][j] == print || (j > 0 && map[i][j - 1] == print);
    }

    private void draw(char[][] map, int a, char print) {
        int start = 1;
        for (int i = 0; a > 0; i += 2) {
            for (int j = start; j < map.length && a > 0; j += 2) {
                map[i][j] = print;
                a--;
            }
            start = start == 1 ? 0 : 1;
        }
    }

    private void fill(char[][] map, char c) {
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length; j++) {
                map[i][j] = c;
            }
        }
    }


    Scanner in;
    PrintWriter out;

    void run() {
        try {
            in = new Scanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new Scanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public Scanner(InputStream f) {
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

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        private int skip() {
            int b;
            while ((b = read()) != -1 && isSpaceChar(b)) ;
            return b;
        }

        private int read() {
            int res = -1;
            try {
                res = br.read();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return res;
        }

        char[] nextCharArray(int size) {
            char[] buf = new char[size];
            int b = skip(), p = 0;
            while (p < size && !(isSpaceChar(b))) {
                buf[p++] = (char) b;
                b = read();
            }
            return size == p ? buf : Arrays.copyOf(buf, p);
        }

        char[][] nextCharMap(int n, int m) {
            char[][] map = new char[n][];
            for (int i = 0; i < n; i++) {
                map[i] = nextCharArray(m);
            }
            return map;
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

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
}