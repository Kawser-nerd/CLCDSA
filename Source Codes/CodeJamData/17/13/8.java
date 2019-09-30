import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class MainC {
    FastScanner in;
    PrintWriter out;

    private int myH, myA, hisH, hisA, incr, decr;

    private class State {
        int h1, h2, a1, a2;

        State(int h1, int h2, int a1, int a2) {
            this.h1 = h1;
            this.h2 = h2;
            this.a1 = a1;
            this.a2 = a2;
        }

        @Override
        public String toString() {
            return "State{" +
                    "h1=" + h1 +
                    ", h2=" + h2 +
                    ", a1=" + a1 +
                    ", a2=" + a2 +
                    '}';
        }

        boolean gameEnd() {
            return h2 <= 0;
        }

        boolean iLost() {
            return h1 <= 0;
        }

        State hisMove() {
            return new State(h1 - Math.max(0,a2), h2, a1, a2);
        }

        State incr() {
            return new State(h1, h2, a1 + incr, a2);
        }

        State decr() {
            return new State(h1, h2, a1, Math.max(0, a2 - decr));
        }

        State attack() {
            return new State(h1, h2 - a1, a1, a2);
        }

        State health() {
            return new State(myH, h2, a1, a2);
        }

        State makeMove(int type) {
            State next;
            switch (type) {
                case 0:
                    next = decr();
                    break;
                case 1:
                    next = incr();
                    break;
                case 2:
                    next = attack();
                    break;
                default:
                    throw new RuntimeException();
            }
            return next;
        }
    }

    ArrayList<State> game = new ArrayList<>();
    void startGame() {
        game.clear();
        game.add(new State(myH, hisH, myA, hisA));
    }

    boolean makeMove(int type) {
        State current = game.get(game.size() - 1);
        State next = current.makeMove(type);
        if (!next.gameEnd()) {
            State after = next.hisMove();
            if (after.iLost()) {
                State A = current.health();
                State B = A.hisMove();
                if (B.iLost()) {
                    return false;
                }
                State C = B.makeMove(type);
                State D = C.hisMove();
                if (D.iLost()) {
                    return false;
                }
                game.add(A);
                game.add(B);
                game.add(C);
                game.add(D);
            } else {
                game.add(next);
                game.add(after);
            }
        } else {
            game.add(next);
        }
        return true;
    }

    boolean win() {
        return game.get(game.size() - 1).gameEnd();
    }


    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            out.print("Case #" + (t + 1) + ": ");
            myH = in.nextInt();
            myA = in.nextInt();
            hisH = in.nextInt();
            hisA = in.nextInt();
            incr = in.nextInt();
            decr = in.nextInt();
            long res = Long.MAX_VALUE;

            for (int step = 10;  ; step = Integer.MAX_VALUE) {
                System.err.println("step = " + step);
                for (int cntD = 0; cntD <= step && cntD <= res; cntD++) {
                    for (int cntU = 0; cntU <= step && cntU <= res; cntU++) {
                        startGame();
                        boolean ok = true;
                        for (int i = 0; i < cntD; i++) {
                            if (!makeMove(0)) {
                                ok = false;
                                break;
                            }
                        }
                        for (int i = 0; i < cntU; i++) {
                            if (!makeMove(1)) {
                                ok = false;
                                break;
                            }
                        }
//                        System.err.println("???" );
                        while (ok && !win()) {
//                            State last = game.get(game.size() - 1);
//                            System.err.println("-> " + last.h1 + " " + last.h2 + " " + last.a1 + " "+ last.a2);
                            if (!makeMove(2)) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) {
//                            System.err.println("score = " + (game.size() + 1) / 2);
//                            for (State s : game) {
//                                System.err.println(s);
//                            }
                            res = Math.min(res, (game.size() + 1) / 2);
                        }
                    }
                }
                if (res == Long.MAX_VALUE || step == Integer.MAX_VALUE) {
                    break;
                }
            }

            out.println(res == Long.MAX_VALUE ? "IMPOSSIBLE" : res);
            System.err.println((t + 1) + "/" + tc + " done");
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("input.txt"));
            out = new PrintWriter(new File("output.txt"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
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

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new MainC().run();
    }
}