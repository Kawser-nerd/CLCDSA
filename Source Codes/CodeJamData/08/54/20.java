import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.HashSet;

/**
 *
 */
public class D {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner("c:/projekty/gcj/input.txt");

            FileOutputStream out = new FileOutputStream("c:/projekty/gcj/output.txt");

            int numberOfCases;
            numberOfCases = scanner.nextInt();

            PrintWriter wr = new PrintWriter(out);
            for (int i = 0; i < numberOfCases; i++) {
                doCase(i + 1, scanner, wr);
            }
            wr.close();
            out.close();

        } catch (IOException e) {
            System.out.println("Error: " + e);
        }
    }

    static class Rock {
        int x, y;

        public Rock(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    private static void doCase(int caseNumber, Scanner sc, PrintWriter wr) throws IOException {
        int h, w, r;
        h = sc.nextInt();
        w = sc.nextInt();
        r = sc.nextInt();

        Rock []rr = new Rock[r];

        HashSet<Integer> rocks  = new HashSet<Integer>();
        for (int i = 0; i < r; i++) {
            int x, y;
            y = sc.nextInt();
            x = sc.nextInt();
            rr[i] = new Rock(x - 1, y - 1);

            rocks.add((x-1) * 10000 + (y-1));
        }

        int [][]board = new int[w][h];

        board[0][0] = 1;


        for (int i = 3; i < 10000; i += 3) {
            int j = 0, k = i;
            while (j < h && k >= 0) {
                int jj, kk;
                if (k < w) {
                    jj = j - 1;
                    kk = k - 2;
                    if (jj >= 0 && jj < h && kk >= 0 && kk < w && !isRock(kk, jj, 10000, rocks)) {
                        if (board[kk][jj] > 0) {
                            board[k][j] = (board[k][j] + board[kk][jj]) % 10007;
                        }
                    }

                    jj = j - 2;
                    kk = k - 1;
    
                    if (jj >= 0 && jj < h && kk >= 0 && kk < w && !isRock(kk, jj, 10000, rocks)) {
                        if (board[kk][jj] > 0) {
                            board[k][j] = (board[k][j] + board[kk][jj]) % 10007;
                        }
                    }
                }
                j++;
                k--;
            }
        }

        
        wr.println("Case #" + caseNumber + ": " + board[w-1][h-1]);
        System.out.println("Case #" + caseNumber + ": " + board[w-1][h-1]);
    }

    private static boolean isRock(int x, int y, int h, HashSet<Integer> rocks) {
        return rocks.contains(x * h + y);
    }


}
