import java.util.Scanner;
import java.util.Locale;
import java.util.Arrays;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;

public class Board implements Runnable {
    private final Scanner scanner;
    private final PrintWriter printer;

    private void solveSingle(int test) {
        int m = scanner.nextInt();
        int n = scanner.nextInt();

        int[][] board = new int[m][n];
        int[][] left = new int[m][n];
        int[][] top = new int[m][n];

        for (int i = 0; i < m; i++) {
            String s = scanner.next();
            for (int j = 0; j < n / 4; j++) {
                char hex = s.charAt(j);
                int value = (hex >= '0' && hex <= '9') ? (hex - '0') : (hex - 'A' + 10);
                for (int k = 0; k < 4; k++) {
                    board[i][4 * j + k] = (value & (1 << (3 - k))) > 0 ? 1 : 0;
                }
            }
        }

        int[] cuts = new int[Math.min(m, n) + 1];
        int diff = 0;

        for (int size = Math.min(m, n); size > 0; size--) {
            int cutCount = 0;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (j > 0 && board[i][j] == 1 - board[i][j - 1]) {
                        left[i][j] = left[i][j - 1] + 1;
                    } else {
                        left[i][j] = board[i][j] != -1 ? 1 : 0;
                    }

                    boolean good = left[i][j] >= size;
                    if (good) {
                        if (i > 0 && board[i - 1][j] == 1 - board[i][j]) {
                            top[i][j] = top[i - 1][j] + 1;
                        } else {
                            top[i][j] = 1;
                        }
                    } else {
                        top[i][j] = 0;
                    }

                    if (top[i][j] >= size) {
                        // cut
                        for (int dx = 0; dx < size; dx++) {
                            for (int dy = 0; dy < size; dy++) {
                                board[i - dx][j - dy] = -1;
                                left[i - dx][j - dy] = 0;
                                top[i - dx][j - dy] = 0;
                            }
                        }
                        cutCount++;
                    }
                }
            }

            if (cutCount > 0) {
                diff++;
                cuts[size] = cutCount;
            }
        }

        printer.println("Case #" + test + ": " + diff);
        for (int i = cuts.length - 1; i >= 0; i--) {
            if (cuts[i] > 0) {
                printer.println(i + " " + cuts[i]);
            }
        }
    }

    private void solve() throws Exception {
        int cases = scanner.nextInt();
        for (int test = 1; test <= cases; test++) {
            solveSingle(test);
        }
    }

    private Board() throws FileNotFoundException {
        scanner = new Scanner(new File("c-large.in"));
        printer = new PrintWriter(new File("c-large.out"));
    }

    public void run() {
        try {
            solve();
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        } finally {
            printer.close();
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Locale.setDefault(Locale.US);
        new Thread(new Board()).start();
    }
}