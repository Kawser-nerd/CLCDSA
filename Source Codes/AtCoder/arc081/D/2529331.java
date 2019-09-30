import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
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
        boolean[][] checkBoard = new boolean[h - 1][w - 1];
        for (int i = 0; i < h - 1; i++) {
            for (int j = 0; j < w - 1; j++) {
                int count = 0;
                if (board[i][j] == '#') {
                    count++;
                }
                if (board[i + 1][j] == '#') {
                    count++;
                }
                if (board[i][j + 1] == '#') {
                    count++;
                }
                if (board[i + 1][j + 1] == '#') {
                    count++;
                }
                if (count % 2 == 0) {
                    checkBoard[i][j] = true;
                }
            }
        }
        int[][] field = new int[board.length][board[0].length - 1];
        for (int i = 0; i < field[0].length; i++) {
            int same = 0;
            int ns = 0;
            for (int j = 0; j < field.length; j++) {
                if (board[j][i] == board[j][i + 1]) {
                    field[j][i] = j + 1 - same;
                    ns = j + 1;
                } else {
                    field[j][i] = j + 1 - ns;
                    same = j + 1;
                }
            }
        }
        System.out.println(largestRectangle(field, '_'));
    }

    int largestRectangle(int[][] field, int blocked) {
        /*
        int[][] field = new int[board.length][board[0].length];
        for (int i = 0; i < field[0].length; i++) {
            int count = 0;
            for (int j = 0; j < field.length; j++) {
                if (board[j][i] == blocked) {
                    field[j][i] = 0;
                    count = 0;
                } else {
                    field[j][i] = ++count;
                }
            }
        }
        */
        int maximumArea = Math.max(h, w);
        for (int i = 0; i < field.length; i++) {
            Deque<RectPair> stack = new LinkedList<>();
            for (int j = 0; j <= field[0].length; j++) {
                RectPair rp =
                        new RectPair(j < field[0].length ? field[i][j] : 0, j);
                if (stack.isEmpty()) {
                    stack.push(rp);
                } else {
                    if (stack.peek().height < rp.height) {
                        stack.push(rp);
                    } else if (stack.peek().height > rp.height) {
                        int target = j;
                        while (!stack.isEmpty() &&
                                stack.peek().height >= rp.height) {
                            RectPair pre = stack.pop();
                            int area = pre.height * (j + 1 - pre.position);
                            maximumArea = Math.max(maximumArea, area);
                            target = pre.position;
                        }
                        rp.position = target;
                        stack.push(rp);
                    }
                }
            }
        }
        return maximumArea;
    }

    /*
    static int largestRectangle(char[][] board, boolean[][] checkBoard, char blocked) {
        int[][] field = new int[board.length][board[0].length];
        for (int i = 0; i < field[0].length; i++) {
            int count = 0;
            for (int j = 0; j < field.length; j++) {
                if (board[j][i] == blocked) {
                    field[j][i] = 0;
                    count = 0;
                } else {
                    field[j][i] = ++count;
                }
            }
        }
        int maximumArea = 0;
        for (int i = 0; i < board.length; i++) {
            Deque<RectPair> stack = new LinkedList<>();
            for (int j = 0; j <= board[0].length; j++) {
                RectPair rp =
                        new RectPair(j < board[0].length ? field[i][j] : 0, j);
                if (stack.isEmpty()) {
                    stack.push(rp);
                } else {
                    if (stack.peek().height <= rp.height) {
                        stack.push(rp);
                    }
                    if (stack.peek().height > rp.height || ) {
                        int target = j;
                        while (!stack.isEmpty() &&
                                stack.peek().height >= rp.height) {
                            RectPair pre = stack.pop();
                            int startI = i + 1 - pre.height;
                            int startJ = pre.position;
                            boolean flag = true;
                            outer:
                            for (int k = startI; k < i; k++) {
                                for (int l = startJ; l < Math.min(j, board[0].length - 1); l++) {
                                    if (!checkBoard[k][l]) {
                                        target = l + 1;
                                        int area = pre.height * (j - pre.position);
                                        System.out.println("rejected: " + startI + " " + i + " " + startJ + " " + j + " " + area);
                                        flag = false;
                                        break outer;
                                    }
                                }
                            }
                            if (flag) {
                                int area = pre.height * (j - pre.position);
                                System.out.println(startI + " " + i + " " + startJ + " " + j + " " + area);
                                maximumArea = Math.max(maximumArea, area);
                                //target = pre.position;
                            }
                        }
                        rp.position = target;
                        stack.push(rp);
                    }
                }
            }
        }
        return maximumArea;
    }
    */

    static class RectPair {
        int height;
        int position;

        RectPair(int height, int position) {
            this.height = height;
            this.position = position;
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