import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class A {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(in.readLine());

        for (int c = 1; c <= cases; c++) {
            if (c > 1)
                in.readLine();
            char[][] board = new char[4][4];
            boolean done = true;
            for (int i = 0; i < 4; i++) {
                String line = in.readLine();
                for (int j = 0; j < 4; j++) {
                    board[i][j] = line.charAt(j);
                    if (board[i][j] == '.')
                        done = false;
                }
            }

            boolean xWin = false;
            boolean oWin = false;
            for (int i = 0; i < 4; i++) {
                boolean x = true;
                boolean o = true;
                for (int j = 0; j < 4; j++) {
                    x &= (board[i][j] == 'X' || board[i][j] == 'T');
                    o &= (board[i][j] == 'O' || board[i][j] == 'T');
                }
                xWin |= x;
                oWin |= o;
            }
            for (int j = 0; j < 4; j++) {
                boolean x = true;
                boolean o = true;
                for (int i = 0; i < 4; i++) {
                    x &= (board[i][j] == 'X' || board[i][j] == 'T');
                    o &= (board[i][j] == 'O' || board[i][j] == 'T');
                }
                xWin |= x;
                oWin |= o;
            }

            boolean x = true;
            boolean o = true;
            for (int i = 0; i < 4; i++) {
                x &= (board[i][i] == 'X' || board[i][i] == 'T');
                o &= (board[i][i] == 'O' || board[i][i] == 'T');
            }
            xWin |= x;
            oWin |= o;

            x = true;
            o = true;
            for (int i = 0; i < 4; i++) {
                x &= (board[i][3 - i] == 'X' || board[i][3 - i] == 'T');
                o &= (board[i][3 - i] == 'O' || board[i][3 - i] == 'T');
            }
            xWin |= x;
            oWin |= o;

            System.out.print("Case #" + c + ": ");
            if (xWin) {
                System.out.println("X won");
            } else if (oWin) {
                System.out.println("O won");
            } else if (done) {
                System.out.println("Draw");
            } else {
                System.out.println("Game has not completed");
            }
        }

    }
}
