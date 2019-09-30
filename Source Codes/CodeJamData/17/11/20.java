import java.util.*;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numCases = sc.nextInt();
        for (int q = 0; q < numCases; q++) {
            int numRows = sc.nextInt();
            int numCols = sc.nextInt();
            int[] freq = new int[26];
            char[][] grid = new char[numRows][];
            int[] maxRow = new int[26];
            Arrays.fill(maxRow, -1);
            int[] minRow = new int[26];
            Arrays.fill(minRow, numRows);
            int[] maxCol = new int[26];
            Arrays.fill(maxCol, -1);
            int[] minCol = new int[26];
            Arrays.fill(minCol, numCols);
            for (int row = 0; row < numRows; row++) {
                grid[row] = sc.next().toCharArray();
                for (int col = 0; col < numCols; col++) {
                    char c = grid[row][col];
                    if (c != '?') {
                        freq[c - 'A']++;
                        maxRow[c - 'A'] = Math.max(maxRow[c - 'A'], row);
                        minRow[c - 'A'] = Math.min(minRow[c - 'A'], row);
                        maxCol[c - 'A'] = Math.max(maxCol[c - 'A'], col);
                        minCol[c - 'A'] = Math.min(minCol[c - 'A'], col);
                    }
                }
            }

            for (char c = 'A'; c <= 'Z'; c++) {
                if (freq[c - 'A'] > 0) {
                    for (int row = minRow[c - 'A']; row <= maxRow[c - 'A']; row++) {
                        for (int col = minCol[c - 'A']; col <= maxCol[c - 'A']; col++) {
                            grid[row][col] = c;
                        }
                    }
                }
            }

//            for (int i = 0; i < numRows; i++) {
//                System.err.println(grid[i]);
//            }

            for (int r1 = 0; r1 < numRows; r1++) {
                for (int c1 = 0; c1 < numCols; c1++) {
                    for (int r2 = 0; r2 < numRows; r2++) {
                        for (int c2 = 0; c2 < numCols; c2++) {
                            TreeMap<Character, Integer> set = new TreeMap<>();
                            for (int row = r1; row <= r2; row++) {
                                for (int col = c1; col <= c2; col++) {
                                    char c = grid[row][col];
                                    Integer count = set.get(c);
                                    if (count == null) {
                                        set.put(c, 1);
                                    } else {
                                        set.put(c, count + 1);
                                    }
                                }
                            }
                            if (set.size() == 2 && set.containsKey('?')) {
                                Map.Entry<Character, Integer> entry = set.lastEntry();
                                char c = entry.getKey();
                                int count = entry.getValue();
                                if (freq[c - 'A'] == count) {
                                    for (int row = r1; row <= r2; row++) {
                                        for (int col = c1; col <= c2; col++) {
                                            if (grid[row][col] == '?') {
                                                grid[row][col] = c;
                                                freq[c - 'A']++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            System.out.printf("Case #%d: ", q+1);
            System.out.println();
            for (int i = 0; i < numRows; i++) {
                System.out.println(grid[i]);
            }
        }
    }
}
