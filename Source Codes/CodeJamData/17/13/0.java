import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("dragon.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("dragon.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Dragon solver = new Dragon();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class Dragon {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int hd = in.nextInt();
            int ad = in.nextInt();
            int hk = in.nextInt();
            int ak = in.nextInt();
            int buff = in.nextInt();
            int debuff = in.nextInt();
            int turns = getNumberOfTurns(hd, ad, hk, ak, buff, debuff);
            out.println("Case #" + testNumber + ": " + (turns < 0 ? "IMPOSSIBLE" : turns));
        }

        private int getNumberOfTurns(int hd, int ad, int hk, int ak, int buff, int debuff) {
            Set<Dragon.State> visited = new HashSet<>();
            List<Dragon.State> queue = new ArrayList<>();
            List<Dragon.State> next = new ArrayList<>();
            Dragon.State initial = new Dragon.State(hd, ad, hk, ak);
            queue.add(initial);
            visited.add(initial);
            int rounds = 1;
            while (!queue.isEmpty()) {
                for (Dragon.State state : queue) {
                    if (state.haveWon()) {
                        return rounds;
                    }
                }
                for (Dragon.State state : queue) {
                    for (Dragon.State to : new Dragon.State[]{state.attack(), state.heal(hd), state.buff(buff), state.debuff(debuff)}) {
                        if (to == null) {
                            continue;
                        }
                        if (visited.add(to)) {
                            next.add(to);
                        }
                    }
                }
                queue.clear();
                List<Dragon.State> t = queue;
                queue = next;
                next = t;
                rounds++;
            }
            return -1;
        }

        static class State {
            int hd;
            int ad;
            int hk;
            int ak;

            public State(int hd, int ad, int hk, int ak) {
                this.hd = hd;
                this.ad = ad;
                this.hk = hk;
                this.ak = ak;
            }

            boolean haveWon() {
                return ad >= hk;
            }

            Dragon.State buff(int buff) {
                if (ak >= hd) {
                    return null;
                }
                return new Dragon.State(hd - ak, ad + buff, hk, ak);
            }

            Dragon.State debuff(int debuff) {
                int newAk = Math.max(0, ak - debuff);
                if (newAk >= hd) {
                    return null;
                }
                return new Dragon.State(hd - newAk, ad, hk, newAk);
            }

            Dragon.State heal(int hp) {
                if (ak >= hp) {
                    return null;
                }
                return new Dragon.State(hp - ak, ad, hk, ak);
            }

            Dragon.State attack() {
                if (ak >= hd) {
                    return null;
                }
                return new Dragon.State(hd - ak, ad, hk - ad, ak);
            }


            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;

                Dragon.State state = (Dragon.State) o;

                if (hd != state.hd) return false;
                if (ad != state.ad) return false;
                if (hk != state.hk) return false;
                return ak == state.ak;
            }


            public int hashCode() {
                int result = hd;
                result = 31 * result + ad;
                result = 31 * result + hk;
                result = 31 * result + ak;
                return result;
            }


            public String toString() {
                return "State{" +
                        "hd=" + hd +
                        ", ad=" + ad +
                        ", hk=" + hk +
                        ", ak=" + ak +
                        '}';
            }

        }

    }

    static class InputReader {
        public BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            return nextToken();
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (line == null) {
                    return null;
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

    }
}

