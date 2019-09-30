package qualifier;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class DFashionShow {
    public static void main (String[] args) {
        try (Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
            int tests = sc.nextInt();
            for (int t = 1; t <= tests; t++) {
                int boardSize = sc.nextInt();
                int existingPieceCount = sc.nextInt();
                boolean[][] originalRooks = new boolean[boardSize][boardSize];
                boolean[][] originalBishops = new boolean[boardSize][boardSize];
                boolean[][] fullRooks = new boolean[boardSize][boardSize];
                boolean[][] fullBishops = new boolean[boardSize][boardSize];
                for (int i = 0; i < existingPieceCount; i++) {
                    char pieceType = sc.next().charAt(0);
                    int y = sc.nextInt() - 1;
                    int x = sc.nextInt() - 1;
                    boolean isRook = pieceType == 'x' || pieceType == 'o';
                    boolean isBishop = pieceType == '+' || pieceType == 'o';
                    if (isRook) {
                        originalRooks[y][x] = true;
                        fullRooks[y][x] = true;
                    }
                    if (isBishop) {
                        originalBishops[y][x] = true;
                        fullBishops[y][x] = true;
                    }
                }
                fillRooks(fullRooks);
                fillBishops(fullBishops);
                int points = 0;
                int modifications = 0;
                for (int y = 0; y < boardSize; y++) {
                    for (int x = 0; x < boardSize; x++) {
                        if (fullRooks[y][x]) points++;
                        if (fullBishops[y][x]) points++;
                        if (fullRooks[y][x] != originalRooks[y][x] || fullBishops[y][x] != originalBishops[y][x]) modifications++;
                    }
                }
                System.out.printf("Case #%d: %d %d%n", t, points, modifications);
                for (int y = 0; y < boardSize; y++) {
                    for (int x = 0; x < boardSize; x++) {
                        if (fullRooks[y][x] != originalRooks[y][x] || fullBishops[y][x] != originalBishops[y][x]) {
                            System.out.printf("%c %d %d%n", getChar(fullRooks[y][x], fullBishops[y][x]), y + 1, x + 1);
                        }
                    }
                }
            }
        }
    }
    
    static char getChar(boolean isRook, boolean isBishop) {
        if (isRook) {
            if (isBishop) {
                return 'o';
            } else {
                return 'x';
            }
        } else {
            if (isBishop) {
                return '+';
            } else {
                return '.'; //Not used
            }
        }
    }
    
    static void fillRooks(boolean[][] rooks) {
        boolean[] columnTaken = new boolean[rooks.length];
        boolean[] rowTaken = new boolean[rooks.length];
        for (int y = 0; y < rooks.length; y++) {
            for (int x = 0; x < rooks.length; x++) {
                if (rooks[y][x]) {
                    columnTaken[x] = true;
                    rowTaken[y] = true;
                }
            }
        }
        for (int y = 0; y < rooks.length; y++) {
            if (rowTaken[y]) continue;
            for (int x = 0; x < rooks.length; x++) {
                if (columnTaken[x]) continue;
                rooks[y][x] = true;
                rowTaken[y] = true;
                columnTaken[x] = true;
                break;
            }
        }
    }
    
    static void fillBishops(boolean[][] bishops) {
        int diagCount = (bishops.length * 2) - 1;
        boolean[] majorDiagTaken = new boolean[diagCount];
        boolean[] minorDiagTaken = new boolean[diagCount];
        for (int y = 0; y < bishops.length; y++) {
            for (int x = 0; x < bishops.length; x++) {
                if (bishops[y][x]) {
                    int majorDiag = majorDiag(x, y, bishops.length);
                    int minorDiag = minorDiag(x, y, bishops.length);
                    majorDiagTaken[majorDiag] = true;
                    minorDiagTaken[minorDiag] = true;
                }
            }
        }
        for (int startY = 0, startX = bishops.length - 1; startY < bishops.length; startY++, startX--) {
            for (int[] startSpot : new int[][] {{0, startY}, {startX, bishops.length - 1}}) {
                int x = startSpot[0];
                int y = startSpot[1];
                while (x < bishops.length && y >= 0) {
                    int majorDiag = majorDiag(x, y, bishops.length);
                    int minorDiag = minorDiag(x, y, bishops.length);
                    if (!(majorDiagTaken[majorDiag] || minorDiagTaken[minorDiag])) {
                        majorDiagTaken[majorDiag] = true;
                        minorDiagTaken[minorDiag] = true;
                        bishops[y][x] = true;
                    }
                    x++;
                    y--;
                }
            }
        }
    }
    
    static int majorDiag(int x, int y, int size) {
        return (y - ((size - 1) - x)) + size - 1;
    }
    
    static int minorDiag(int x, int y, int size) {
        return (y - x) + size - 1;
    }
}
