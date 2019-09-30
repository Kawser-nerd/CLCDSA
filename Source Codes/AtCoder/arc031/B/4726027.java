import java.util.Scanner;

public class Main {
    private static final int[] dx = {1, 0, -1, 0};
    private static final int[] dy = {0, 1, 0, -1};

    private static void dfs(int x, int y, char[][] b) {
        if(b[x][y] == 'x') return;
        b[x][y] = 'x';
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < 10 && 0 <= ny && ny < 10) dfs(nx, ny, b);
        }
    }

    private static boolean check(int x, int y, char[][] b) {
        dfs(x, y, b);
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(b[i][j] == 'o') return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        char[][] a = new char[10][10];
        for(int i = 0; i < 10; i++) {
            String str = sc.next();
            for(int j = 0; j < 10; j++) {
                a[i][j] = str.charAt(j);
            }
        }

        boolean flag = false;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                char[][] b = new char[10][10];
                for(int x = 0; x < 10; x++) {
                    for(int y = 0; y < 10; y++) {
                        b[x][y] = a[x][y];
                    }
                }
                b[i][j] = 'o';
                if(check(i, j, b)) {
                    flag = true;
                    break;
                }
            }
        }

        System.out.println(flag? "YES" : "NO");

        sc.close();
    }
}