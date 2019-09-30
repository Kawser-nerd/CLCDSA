import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int h = sc.nextInt();
        int w = sc.nextInt();
        int[][] check = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        boolean[][] mass = new boolean[h][w];

        for (int i = 0; i < h; i++) {
            String s = sc.next();
            for (int j = 0; j < w; j++) {
                mass[i][j] = s.charAt(j) == '#';
            }
        }

        boolean isAns = true;
        label: for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (mass[i][j]) {
                    boolean isCheck = false;
                    for (int z = 0; z < check.length; z++) {
                        int y = i+check[z][0];
                        int x = j+check[z][1];
                        if (y >= h || y < 0 || x >= w || x < 0)
                            continue;

                        if(mass[y][x]) {
                            isCheck = true;
                            break;
                        }
                    }
                    if (!(isCheck)) {
                        isAns = false;
                        break label;
                    }
                }
            }
        }

        System.out.println(isAns ? "Yes" : "No");
    }
}