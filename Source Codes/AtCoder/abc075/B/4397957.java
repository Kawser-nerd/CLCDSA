import java.util.*;
import java.util.stream.IntStream;

public class Main {

    public static boolean found = false;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int h = sc.nextInt();
        int w = sc.nextInt();
        char[][] board = new char[h][w];

        int[][] dt =  new int[][] {
                new int[] {1, 0},
                new int[] {1, 1},
                new int[] {0, 1},
                new int[] {-1, 1},
                new int[] {-1, 0},
                new int[] {-1, -1},
                new int[] {0, -1},
                new int[] {1, -1}
        };

        for (int i = 0; i < h; i++) {
            String line = sc.next();
            board[i] = line.toCharArray();
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {

                if (board[i][j] != '#') {
                    int count = 0;

                    for (int k = 0; k < dt.length; k++) {
                        int x = i + dt[k][0];
                        int y = j + dt[k][1];

                        if ((0 <= x && x < h) && (0 <= y && y < w) && board[x][y] == '#') {
                            count++;
                        }
                    }
                    board[i][j] = (char)(count + '0');
                }

                System.out.print(board[i][j]);
            }
            System.out.println("");
        }



    }

}