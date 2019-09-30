import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int w = sc.nextInt();
        int h = sc.nextInt();
        int n = sc.nextInt();
        boolean[][] area = new boolean[h][w];

        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int a = sc.nextInt();

            switch (a) {
                case 1:
                    for (int y1 = 0; y1 < h; y1++) {
                        for (int x1 = 0; x1 < x; x1++) {
                            area[y1][x1] = true;
                        }
                    }
                    break;

                case 2:
                    for (int y1 = 0; y1 < h; y1++) {
                        for (int x1 = x; x1 < w; x1++) {
                            area[y1][x1] = true;
                        }
                    }
                    break;

                case 3:
                    for (int y1 = 0; y1 < y; y1++) {
                        for (int x1 = 0; x1 < w; x1++) {
                            area[y1][x1] = true;
                        }
                    }
                    break;

                case 4:
                    for (int y1 = y; y1 < h; y1++) {
                        for (int x1 = 0; x1 < w; x1++) {
                            area[y1][x1] = true;
                        }
                    }
                    break;
            }
        }

        int ans = 0;
        for (boolean[] isArray : area) {
            for (boolean isCell : isArray) {
                if (!(isCell))
                    ans++;
            }
        }

        System.out.println(ans);
    }
}