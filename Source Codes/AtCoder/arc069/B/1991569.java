import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        Solver s = new Solver();
        for (int i = 1; i <= t; i++) {
            s.solve(i, in, out);
        }
        out.close();
    }

}

class Solver {
    void solve(int test, InputReader in, PrintWriter out) throws IOException {
        in.nextInt();
        String s = in.next();
        if (sheepsheep(s)) {
            out.println(formSheepSheep(s));
        } else if (sheepwolf(s)) {
            out.println(formSheepWolf(s));
        } else if (wolfsheep(s)) {
            out.println(formWolfSheep(s));
        } else if (wolfwolf(s)) {
            out.println(formWolfWolf(s));
        } else {
            out.println(-1);
        }
    }

    private String formWolfWolf(String s) {
        char[] st = new char[s.length()];
        int n = st.length;
        st[0] = 'W';
        st[1] = 'W';
        st[n - 1] = s.charAt(0) != 'o' ? st[1] : opposite(st[1]);
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == 'o') {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = st[i - 1];
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    }
                }
            } else {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = (st[i - 1]);
                    }
                }
            }
        }
        return new String (st);
    }

    private String formWolfSheep(String s) {
        char[] st = new char[s.length()];
        int n = st.length;
        st[0] = 'W';
        st[1] = 'S';
        st[n - 1] = s.charAt(0) != 'o' ? st[1] : opposite(st[1]);
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == 'o') {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = st[i - 1];
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    }
                }
            } else {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = (st[i - 1]);
                    }
                }
            }
        }
        return new String(st);
    }

    private String formSheepSheep(String s) {
        char[] st = new char[s.length()];
        int n = st.length;
        st[0] = 'S';
        st[1] = 'S';
        st[n - 1] = s.charAt(0) == 'o' ? st[1] : opposite(st[1]);
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == 'o') {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = st[i - 1];
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    }
                }
            } else {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = (st[i - 1]);
                    }
                }
            }
        }
        return new String(st);
    }

    private String formSheepWolf(String s) {
        char[] st = new char[s.length()];
        int n = st.length;
        st[0] = 'S';
        st[1] = 'W';
        st[n - 1] = s.charAt(0) == 'o' ? st[1] : opposite(st[1]);
        for (int i = 1; i < s.length(); i++) {
            //            System.out.println(st);
            if (s.charAt(i) == 'o') {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = st[i - 1];
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    }
                }
            } else {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = (st[i - 1]);
                    }
                }
            }
        }
        return new String (st);
    }

    private boolean wolfwolf(String s) {
        char[] st = new char[s.length()];
        int n = st.length;
        st[0] = 'W';
        st[1] = 'W';
        st[n - 1] = s.charAt(0) != 'o' ? st[1] : opposite(st[1]);
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == 'o') {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = st[i - 1];
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] != st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] != st[0]) {
                            return false;
                        }
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] == st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] == st[0]) {
                            return false;
                        }
                    }
                }
            } else {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] == st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] == st[0]) {
                            return false;
                        }
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = (st[i - 1]);
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] != st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] != st[0]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    private boolean wolfsheep(String s) {
        char[] st = new char[s.length()];
        int n = st.length;
        st[0] = 'W';
        st[1] = 'S';
        st[n - 1] = s.charAt(0) != 'o' ? st[1] : opposite(st[1]);
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == 'o') {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = st[i - 1];
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] != st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] != st[0]) {
                            return false;
                        }
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] == st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] == st[0]) {
                            return false;
                        }
                    }
                }
            } else {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] == st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] == st[0]) {
                            return false;
                        }
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = (st[i - 1]);
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] != st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] != st[0]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    private boolean sheepwolf(String s) {
        char[] st = new char[s.length()];
        int n = st.length;
        st[0] = 'S';
        st[1] = 'W';
        st[n - 1] = s.charAt(0) == 'o' ? st[1] : opposite(st[1]);
        for (int i = 1; i < s.length(); i++) {
//            System.out.println(st);
            if (s.charAt(i) == 'o') {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = st[i - 1];
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] != st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] != st[0]) {
                            return false;
                        }
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] == st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] == st[0]) {
                            return false;
                        }
                    }
                }
            } else {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] == st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] == st[0]) {
                            return false;
                        }
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = (st[i - 1]);
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] != st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] != st[0]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    private boolean sheepsheep(String s) {
        char[] st = new char[s.length()];
        int n = st.length;
        st[0] = 'S';
        st[1] = 'S';
        st[n - 1] = s.charAt(0) == 'o' ? st[1] : opposite(st[1]);
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == 'o') {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = st[i - 1];
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] != st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] != st[0]) {
                            return false;
                        }
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] == st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] == st[0]) {
                            return false;
                        }
                    }
                }
            } else {
                if (st[i] == 'S') {
                    if (i + 1 < n - 1) {
                        st[i + 1] = opposite(st[i - 1]);
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] == st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] == st[0]) {
                            return false;
                        }
                    }
                } else {
                    if (i + 1 < n - 1) {
                        st[i + 1] = (st[i - 1]);
                    } else if (i + 1 == n - 1) {
                        if (st[i - 1] != st[i + 1]) {
                            return false;
                        }
                    } else {
                        if (st[i - 1] != st[0]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    private char opposite(char c) {
        if (c == 'S') return 'W';
        else return 'S';
    }
}

class InputReader {
    BufferedReader br;
    StringTokenizer st;

    public InputReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = null;
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public String nextLine() throws IOException {
        return br.readLine();
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}