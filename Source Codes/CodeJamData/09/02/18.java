import java.awt.geom.Area;
import java.awt.geom.Point2D;
import java.io.*;
import java.util.*;
import java.util.regex.*;

public class Watersheds {
    
    static Map<Point2D, Integer> pointToBasin = new HashMap<Point2D, Integer>();
    
    public static void main(String[] args) throws IOException {
        File input = new File("B-large.in");
        Scanner in = new Scanner(input);
        File output = new File("B-large.out");
        PrintWriter out = new PrintWriter(output);
        
        int testCount = in.nextInt();
        
        for (int i = 1; i <= testCount; i++) {
            int rows = in.nextInt();
            int cols = in.nextInt();
            
            int[][] altitudes = new int[rows][cols];
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < cols; k++) {
                    altitudes[j][k] = in.nextInt();
                }
            }
            
            char[][] solution = solve(altitudes);
            out.format("Case #%d:\r\n", i);
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < cols; k++) {
                    out.print(solution[j][k]);
                    if (k < cols - 1) {
                        out.print(' ');
                    }
                }
                out.println();
            }
        }
        
        System.err.println("Done!");
        out.close();
    }
    
    public static int[] neighbors(int[][] altitudes, int r, int c) {
        int[] n = new int[4];  // NWES, override order
        n[0] = (r > 0) ? altitudes[r - 1][c] : -1;
        n[1] = (c > 0) ? altitudes[r][c - 1] : -1;
        n[2] = (c < altitudes[r].length - 1) ? altitudes[r][c + 1] : -1;
        n[3] = (r < altitudes.length - 1) ? altitudes[r + 1][c] : -1;
        return n;
    }
    
    public static boolean isSink(int[][] altitudes, int r, int c) {
        return findChild(altitudes, r, c) == null;
    }
    
    public static List<int[]> findParents(int[][] altitudes, int r, int c) {
        int[] neighbors = neighbors(altitudes, r, c);
        List<int[]> parents = new ArrayList<int[]>();
        for (int i = 0; i < neighbors.length; i++) {
            if (neighbors[i] > altitudes[r][c]) {
                int[] parent = null;
                switch (i) {
                    case 0:
                        parent = new int[] {r - 1, c};
                        break;
                    case 1:
                        parent = new int[] {r, c - 1};
                        break;
                    case 2:
                        parent = new int[] {r, c + 1};
                        break;
                    case 3:
                        parent = new int[] {r + 1, c};
                        break;
                }

                int[] parentsChild = findChild(altitudes, parent[0], parent[1]);
                if (Arrays.equals(new int[] {r, c}, parentsChild)) {
                    parents.add(parent);
                }
            }
        }

        return parents;
    }
    
    public static int[] findChild(int[][] altitudes, int r, int c) {
        int[] neighbors = neighbors(altitudes, r, c);
        int min = altitudes[r][c];
        int cell = -1;
        for (int i = 0; i < neighbors.length; i++) {
            if (neighbors[i] >= 0 && neighbors[i] < min) {
                min = neighbors[i];
                cell = i;
            }
        }
        
        switch (cell) {
            case 0:
                return new int[] {r - 1, c};
            case 1:
                return new int[] {r, c - 1};
            case 2:
                return new int[] {r, c + 1};
            case 3:
                return new int[] {r + 1, c};
        }
        return null;
    }
    
    public static char[][] solve(int[][] altitudes) {
        int rows = altitudes.length;
        int cols = altitudes[0].length;
        char[][] basins = new char[rows][cols];
        
        char currChar = 'A';
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (isSink(altitudes, i, j)) {
                    sprawlUp(altitudes, i, j, basins, currChar);
                    currChar++;
                }
            }
        }
        
        return relabel(basins);
    }
    
    // modifies the array
    public static char[][] relabel(char[][] basins) {
        boolean[] found = new boolean[26];
        List<Character> order = new ArrayList<Character>();
        
        for (int i = 0; i < basins.length; i++) {
            for (int j = 0; j < basins[i].length; j++) {
                char c = basins[i][j];
                if (!found[c - 'A']) {
                    found[c - 'A'] = true;
                    order.add(c);
                }
            }
        }
        
        char current = 'a';
        for (char toReplace : order) {
            for (int i = 0; i < basins.length; i++) {
                for (int j = 0; j < basins[i].length; j++) {
                    if (basins[i][j] == toReplace) {
                        basins[i][j] = current;
                    }
                }
            }
            current++;
        }
        
        return basins;
    }
    
    public static void sprawlUp(int[][] altitudes, int r, int c,
            char[][] basins, char marker) {
       Set<int[]> visited = new HashSet<int[]>();
       Queue<int[]> q = new LinkedList<int[]>();
       q.offer(new int[] {r, c});
       while (!q.isEmpty()) {
           int[] pos = q.poll();
           if (!visited.contains(pos)) {
               basins[pos[0]][pos[1]] = marker;
               // Expand the node.
               for (int[] parent : findParents(altitudes, pos[0], pos[1])) {
                   q.offer(parent);
               }
               visited.add(pos);
           }
       }
    }
}