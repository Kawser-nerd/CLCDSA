import java.util.*;

public class Main {

    private static final int MAP_SIZE = 10;
    private static final char LAND = 'o';
    private static final char SEA = 'x';

    public static void main(String[] args) {
        new Main().execute();
    }


    public void execute() {
        Scanner sc = new Scanner(System.in);
        final char[][] map = new char[MAP_SIZE][MAP_SIZE];

        int sx = -1;
        int sy = -1;
        for (int i = 0; i < MAP_SIZE; i++) {
            String s = sc.nextLine();
            for (int j = 0; j < MAP_SIZE; j++) {
                map[i][j] = s.charAt(j);
                if (map[i][j] == LAND) {
                    sx = i;
                    sy = j;
                }
            }
        }

        for (int i = 0; i < MAP_SIZE; i++) {
            for (int j = 0; j < MAP_SIZE; j++) {
                char[][] copy = mapDeepCopy(map);
                copy[i][j] = LAND;
                char[][] land = blankMap();
                updateMap(sx, sy, copy, land);
                if (mapEquals(land, copy)) {
                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");
        sc.close();
    }

    private void updateMap(int x, int y, char[][] master, char[][] map) {
        if (x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE) {
            if (map[x][y] == SEA && master[x][y] == LAND) {
                map[x][y] = LAND;
                updateMap(x + 1, y, master, map);
                updateMap(x - 1, y, master, map);
                updateMap(x, y + 1, master, map);
                updateMap(x, y - 1, master, map);
            }
        }
    }

    private char[][] blankMap() {
        char[][] blankMap = new char[MAP_SIZE][MAP_SIZE];
        for (int i = 0; i < MAP_SIZE; i++) {
            for (int j = 0; j < MAP_SIZE; j++) {
                blankMap[i][j] = SEA;
            }
        }
        return blankMap;
    }


    private char[][] mapDeepCopy(char[][] originalMap) {
        char[][] copyMap = new char[MAP_SIZE][MAP_SIZE];
        for (int i = 0; i < MAP_SIZE; i++) {
            for (int j = 0; j < MAP_SIZE; j++) {
                copyMap[i][j] = originalMap[i][j];
            }
        }
        return copyMap;
    }

    private boolean mapEquals(char[][] ma, char[][] mb) {
        if (ma.length != mb.length) {
            return false;
        }
        for (int i = 0; i < ma.length; i++) {
            if (ma[i].length != mb[i].length) {
                return false;
            }
            for (int j = 0; j < ma[i].length; j++) {
                if (ma[i][j] != mb[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}