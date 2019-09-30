import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int R = sc.nextInt();
            int C = sc.nextInt();
            char[][] grid = new char[R][C];
            int[] rowCounts = new int[R];
            int[] colCounts = new int[C];
            for (int r = 0; r < R; r++) {
                String row = sc.next();
                for (int c = 0; c < C; c++) {
                    grid[r][c] = row.charAt(c);
                    if (grid[r][c] != '.') {
                        rowCounts[r]++;
                        colCounts[c]++;
                    }
                }
            }

            int numArrows = 0;
            boolean possible = true;
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (grid[r][c] == '.') {
                        continue;
                    }
                    if (rowCounts[r] == 1 && colCounts[c] == 1) {
                        possible = false;
                    }
                    if (!pointsToArrow(grid, r, c)) {
                        numArrows++;
                    }
                }
            }
            String output = possible ? String.valueOf(numArrows) : "IMPOSSIBLE";
            System.out.println("Case #" + caseNum + ": " + output);
        }
    }

    private static boolean pointsToArrow(char[][] grid, int r, int c) {
        switch (grid[r][c]) {
        case '^':
            for (int i = 0; i < r; i++) {
                if (grid[i][c] != '.') {
                    return true;
                }
            }
            return false;
        case '>':
            for (int i = c + 1; i < grid[0].length; i++) {
                if (grid[r][i] != '.') {
                    return true;
                }
            }
            return false;
        case 'v':
            for (int i = r + 1; i < grid.length; i++) {
                if (grid[i][c] != '.') {
                    return true;
                }
            }
            return false;
        case '<':
            for (int i = 0; i < c; i++) {
                if (grid[r][i] != '.') {
                    return true;
                }
            }
            return false;
        }
        return true;
    }
}
