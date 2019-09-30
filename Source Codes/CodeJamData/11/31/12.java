import java.io.*;
import java.util.Scanner;

public class A {

    private static final String FILE_NAME = "A-large";

    public static void main (String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME+".in"));
        Scanner scanner = new Scanner(in);
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME+".out"));
        int t = scanner.nextInt();
        for (int c = 1; c <= t; ++c) {
            int rr = scanner.nextInt();
            int cc = scanner.nextInt();
            scanner.nextLine();
            char[][] board = new char[rr][cc];
            for (int i = 0; i < rr; ++i) {
                String row = scanner.nextLine();
                for (int j = 0; j < cc; ++j) {
                    board[i][j] = row.charAt(j);
                }
            }
            boolean ok = true;
            for (int i = 0; i < rr && ok; ++i) {
                for (int j = 0; j < cc; ++j) {
                    if (board[i][j] == '#') {
                        if (i == rr-1 || j == cc-1 || board[i][j+1] != '#' || board[i+1][j] != '#' || board[i+1][j+1] != '#') {
                            ok = false;
                            break;
                        }
                        board[i][j] = board[i+1][j+1] = '/';
                        board[i+1][j] = board[i][j+1] = '\\';
                    }
                }
            }
            StringBuilder ans = new StringBuilder();
            ans.append("Case #");
            ans.append(c);
            ans.append(":\n");
            if (ok) {
                for (int i = 0; i < rr; ++i) {
                    if (i > 0) {
                        ans.append("\n");
                    }
                    ans.append(new String(board[i]));
                }
            } else {
                ans.append("Impossible");
            }
            out.write(ans+"\n");
            System.out.println(ans);
        }
        out.close();
    }
}
