import java.util.*;
import java.io.*;

public class PA implements Runnable {
    static class Data {
        private StringTokenizer tok;
        private final BufferedReader rd;
        private final PrintWriter wr;

        Data() {
            tok = null;
            rd = new BufferedReader(new InputStreamReader(System.in));
            wr = new PrintWriter(System.out);
        }

        Data(String name) throws IOException {
            tok = null;
            rd = new BufferedReader(new FileReader(new File(name + ".in")));
            wr = new PrintWriter(new File(name + ".out"));
        }

        void println(String line) {
            wr.println(line);
        }

        void close() throws IOException {
            rd.close();
            wr.close();
        }

        String nextToken() throws IOException {
            while (tok == null || !tok.hasMoreTokens()) {
                tok = new StringTokenizer(rd.readLine());
            }
            return tok.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        static Data console() {
            return new Data();
        }

        static Data files(String name) throws IOException {
            return new Data(name);
        }
    }

    public static void main(String[] args) {
        new Thread(new PA()).start();
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (Throwable t) {
            throw new RuntimeException(t);
        }
    }

    static class Pos {
        final char ch;
        final int r;
        final int c;

        Pos(char ch, int r, int c) {
            this.ch = ch;
            this.r = r;
            this.c = c;
        }
    }

    static class Node {
        Node left;
        Node right;

        char ch;
        int r;
        int c;
        int rmin;
        int rmax;
        int cmin;
        int cmax;

        Node(char ch, int r, int c) {
            this.left = null;
            this.right = null;
            this.ch = ch;
            this.r = r;
            this.c = c;
            this.rmin = 0;
            this.rmax = 0;
            this.cmin = 0;
            this.cmax = 0;
        }

        boolean has(int r, int c) {
            if (rmin <= r && r <= rmax && cmin <= c && c <= cmax) {
                return true;
            }
            return false;
        }

        void add(char ch, int r, int c) {
            if (left != null || right != null) {
                if (left.has(r, c)) {
                    left.add(ch, r, c);
                    return;
                } else if (right.has(r, c)) {
                    right.add(ch, r, c);
                    return;
                }
                return;
            }
            if (this.r < r) {
                left = new Node(this.ch, this.r, this.c);
                left.rmin = this.rmin;
                left.rmax = this.r;
                left.cmin = this.cmin;
                left.cmax = this.cmax;

                right = new Node(ch, r, c);
                right.rmin = this.r + 1;
                right.rmax = this.rmax;
                right.cmin = this.cmin;
                right.cmax = this.cmax;
            } else if (this.r > r) {
                left = new Node(this.ch, this.r, this.c);
                left.rmin = this.r;
                left.rmax = this.rmax;
                left.cmin = this.cmin;
                left.cmax = this.cmax;

                right = new Node(ch, r, c);
                right.rmin = this.rmin;
                right.rmax = this.r - 1;
                right.cmin = this.cmin;
                right.cmax = this.cmax;
            } else if (this.c < c) {
                left = new Node(this.ch, this.r, this.c);
                left.rmin = this.rmin;
                left.rmax = this.rmax;
                left.cmin = this.cmin;
                left.cmax = this.c;

                right = new Node(ch, r, c);
                right.rmin = this.rmin;
                right.rmax = this.rmax;
                right.cmin = this.c + 1;
                right.cmax = this.cmax;
            } else {
                left = new Node(this.ch, this.r, this.c);
                left.rmin = this.rmin;
                left.rmax = this.rmax;
                left.cmin = this.c;
                left.cmax = this.cmax;

                right = new Node(ch, r, c);
                right.rmin = this.rmin;
                right.rmax = this.rmax;
                right.cmin = this.cmin;
                right.cmax = this.c - 1;
            }

            this.ch = '?';
            this.r = -1;
            this.c = -1;
        }

        public void render(char[][] f) {
            if (left != null || right != null) {
                left.render(f);
                right.render(f);
                return;
            }
            for (int i = rmin; i <= rmax; ++i) {
                for (int j = cmin; j <= cmax; ++j) {
                    f[i][j] = ch;
                }
            }
        }
    }

    static class Test {
        final int r;
        final int c;
        final char[][] f;

        Test(int ti, Data data) throws IOException {
            data.println(String.format("Case #%d:", ti));
            r = data.nextInt();
            c = data.nextInt();
            f = new char[r][c];
            ArrayList<Pos> p = new ArrayList<>();
            for (int j = 0; j < r; ++j) {
                String line = data.nextToken().trim();
                for (int k = 0; k < c; ++k) {
                    f[j][k] = line.charAt(k);
                    if (f[j][k] != '?') {
                        p.add(new Pos(f[j][k], j, k));
                    }
                }
            }


            if (p.size() == 0) {
                Node root = new Node('A', 0, 0);
                root.rmin = 0;
                root.rmax = r - 1;
                root.cmin = 0;
                root.cmax = c - 1;
                root.render(f);
                result(data);
                return;
            }

            Pos pos = p.get(0);
            Node root = new Node(pos.ch, pos.r, pos.c);
            root.rmin = 0;
            root.rmax = r - 1;
            root.cmin = 0;
            root.cmax = c - 1;
            for (int i = 1; i < p.size(); ++i) {
                pos = p.get(i);
                root.add(pos.ch, pos.r, pos.c);
            }
            root.render(f);
            result(data);
        }

        private void result(Data data) {
            for (int i = 0; i < r; ++i) {
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < c; ++j) {
                    sb.append(f[i][j]);
                }
                data.println(sb.toString());
            }
        }
    }

    private void solve() throws IOException {
        Data data = Data.files("a");

        int t = data.nextInt();
        for (int i = 0; i < t; ++i) {
            Test test = new Test(i + 1, data);
        }

        data.close();
    }
}
