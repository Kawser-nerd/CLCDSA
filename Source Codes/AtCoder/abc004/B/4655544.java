import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String[][] board = new String[4][4];
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++){
                board[i][j] = sc.next();
            }
        }

        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                System.out.print(board[3-i][3-j]);
                if (j != 3) {
                    System.out.print(' ');
                }
            }
            System.out.println();
        }
    }
}