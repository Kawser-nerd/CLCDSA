import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Main main = new Main();
        int testCount = in.nextInt();
        for (int testNo = 1; testNo <= testCount; testNo++) {
            main.solve(testNo, in);
        }
    }

    private void solve(int testNo, Scanner in) {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] board = new char[n][n];
        for (char[] chars : board) {
            Arrays.fill(chars, '.');
        }
        while (m-- > 0) {
            char c = in.next().charAt(0);
            int i = in.nextInt() - 1;
            int j = in.nextInt() - 1;
            board[i][j] = c;
        }
        boolean[][] graphRowCol = new boolean[n][n];
        boolean[] invalidIRowCol = new boolean[n];
        boolean[] invalidJRowCol = new boolean[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'x' || board[i][j] == 'o') {
                    invalidIRowCol[i] = true;
                    invalidJRowCol[j] = true;
                } else {
                    graphRowCol[i][j] = true;
                }
            }
        }
        int[] matchRowCol = graphMatch(n, graphRowCol, invalidIRowCol, invalidJRowCol);
        boolean[][] graphDiag = new boolean[2 * n - 1][2 * n - 1];
        boolean[] invalidIDiag = new boolean[2 * n - 1];
        boolean[] invalidJDiag = new boolean[2 * n - 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '+' || board[i][j] == 'o') {
                    invalidIDiag[i - j + n - 1] = true;
                    invalidJDiag[i + j] = true;
                } else {
                    graphDiag[i - j + n - 1][i + j] = true;
                }
            }
        }
        int[] matchDiag = graphMatch(2 * n - 1, graphDiag, invalidIDiag, invalidJDiag);
        byte[][] result = new byte[n][n];
        for (int j = 0; j < n; j++) {
            if (matchRowCol[j] != -1) {
                int i = matchRowCol[j];
                result[i][j] |= 1;
            }
        }
        for (int y = 0; y < 2 * n - 1; y++) {
            if (matchDiag[y] != -1) {
                int x = matchDiag[y];
                int i = (x + y - (n - 1)) / 2;
                int j = y - i;
                result[i][j] |= 2;
            }
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'o') {
                    answer += 2;
                } else if (board[i][j] == 'x' || board[i][j] == '+') {
                    answer++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (result[i][j] == 3) {
                    answer += 2;
                } else if (result[i][j] > 0) {
                    answer++;
                }
            }
        }
        String symbols = ".x+o";
        List<String> modifications = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (result[i][j] > 0) {
                    if (board[i][j] != '.') {
                        modifications.add("o " + (i + 1) + " " + (j + 1));
                    } else {
                        modifications.add(symbols.charAt(result[i][j]) + " " + (i + 1) + " " + (j + 1));
                    }
                }
            }
        }
        System.out.println("Case #" + testNo + ": " + answer + " " + modifications.size());
        for (String modification : modifications) {
            System.out.println(modification);
        }
    }

    int[] graphMatch(int n, boolean[][] graph, boolean[] invalidI, boolean[] invalidJ) {
        int[] matchJ = new int[n];
        boolean[] usedJ = new boolean[n];
        Arrays.fill(matchJ, -1);
        for (int i = 0; i < n; i++) {
            if (!invalidI[i]) {
                Arrays.fill(usedJ, false);
                search(i, n, graph, usedJ, matchJ, invalidI, invalidJ);
            }
        }
        return matchJ;
    }

    private boolean search(int i, int n, boolean[][] graph, boolean[] usedJ, int[] matchJ, boolean[] invalidI, boolean[] invalidJ) {
        if (invalidI[i]) {
            throw new RuntimeException();
        }
        for (int j = 0; j < n; j++) {
            if (!invalidJ[j] && graph[i][j] && !usedJ[j]) {
                usedJ[j] = true;
                if (matchJ[j] == -1 || search(matchJ[j], n, graph, usedJ, matchJ, invalidI, invalidJ)) {
                    matchJ[j] = i;
                    return true;
                }
            }
        }
        return false;
    }

}
