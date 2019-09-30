import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int h, w;
    char[][] board;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        h = sc.nextInt();
        w = sc.nextInt();
        board = new char[h][w];
        for (int i = 0; i < h; i++) {
            board[i] = sc.next().toCharArray();
        }
        solve();
    }

    void solve() {
        boolean[][] blackOriginal = new boolean[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '#') {
                    boolean flag = true;
                    if (i > 0) {
                        if (j > 0 && board[i - 1][j - 1] == '.') {
                                flag = false;
                        }
                        if (j < w - 1 && board[i - 1][j + 1] == '.') {
                                flag = false;
                        }
                        if (board[i - 1][j] == '.') {
                            flag = false;
                        }
                    }
                    if (flag && i < h - 1) {
                        if (j > 0 && board[i + 1][j - 1] == '.') {
                            flag = false;
                        }
                        if (j < w - 1 && board[i + 1][j + 1] == '.') {
                            flag = false;
                        }
                        if (board[i + 1][j] == '.') {
                            flag = false;
                        }
                    }
                    if (flag) {
                        if (j > 0 && board[i][j - 1] == '.') {
                            flag = false;
                        }
                        if (j < w - 1 && board[i][j + 1] == '.') {
                            flag = false;
                        }
                    }
                    if (flag) {
                        blackOriginal[i][j] = true;
                    }
                }
            }
        }
        char[][] reproducedBoard = new char[h][w];
        for (char[] arr : reproducedBoard) {
            Arrays.fill(arr, '.');
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if(blackOriginal[i][j]) {
                    reproducedBoard[i][j] = '#';
                    if (i > 0) {
                        if (j > 0) {
                            reproducedBoard[i - 1][j - 1] = '#';
                        }
                        if (j < w - 1) {
                            reproducedBoard[i - 1][j + 1] = '#';
                        }
                        reproducedBoard[i - 1][j] = '#';
                    }
                    if (i < h - 1) {
                        if (j > 0) {
                            reproducedBoard[i + 1][j - 1] = '#';
                        }
                        if (j < w - 1) {
                            reproducedBoard[i + 1][j + 1] = '#';
                        }
                        reproducedBoard[i + 1][j] = '#';
                    }
                    if (j > 0) {
                        reproducedBoard[i][j - 1] = '#';
                    }
                    if (j < w - 2) {
                        reproducedBoard[i][j + 1] = '#';
                    }
                }
            }
        }
        boolean match = true;
        outer:
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] != reproducedBoard[i][j]) {
                    match = false;
                    break outer;
                }
            }
        }
        if (match) {
            System.out.println("possible");
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    System.out.print(blackOriginal[i][j] ? '#' : '.');
                }
                System.out.println();
            }
        } else {
            System.out.println("impossible");
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}