import java.io.*;
import java.util.Scanner;

public class Noisy {

    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    public static void main (String...args) throws IOException {
        Scanner in = new Scanner(new File("B-large.in"));
        PrintWriter out = new PrintWriter(new FileWriter("Noisy.out"));
        int loops = in.nextInt();
        for (int loop = 0; loop < loops; loop++) {
            int r = in.nextInt();
            int c = in.nextInt();
            int n = in.nextInt();
            int ans = 0;
            if((r * c + 1) / 2 >= n) {
                ans = 0;
            }
            else {
                boolean[][] occupied = new boolean[r][c];
                int[] pains = new int[5];
                int left = n;
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if((i + j) % 2 == 0) {
                            occupied[i][j] = true;
                            left--;
                        }
                    }
                }
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if(!occupied[i][j]) {
                            int pain = 0;
                            for (int k = 0; k < 4; k++) {
                                try {
                                    if (occupied[i + dx[k]][j + dy[k]]) {
                                        pain++;
                                    }
                                }
                                catch(Exception e) {}
                            }
                            pains[pain]++;
                        }
                    }
                }
                int ow = 0;
                out: for (int i = 0; i < left; i++) {
                    for (int j = 0; j < 5; j++) {
                        if(pains[j] > 0) {
                            ow += j;
                            pains[j]--;
                            continue out;
                        }
                    }
                }

                //////

                occupied = new boolean[r][c];
                pains = new int[5];
                left = n;
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if((i + j) % 2 == 1) {
                            occupied[i][j] = true;
                            left--;
                        }
                    }
                }
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if(!occupied[i][j]) {
                            int pain = 0;
                            for (int k = 0; k < 4; k++) {
                                try {
                                    if (occupied[i + dx[k]][j + dy[k]]) {
                                        pain++;
                                    }
                                }
                                catch(Exception e) {}
                            }
                            pains[pain]++;
                        }
                    }
                }
                int ow2 = 0;
                out: for (int i = 0; i < left; i++) {
                    for (int j = 0; j < 5; j++) {
                        if(pains[j] > 0) {
                            ow2 += j;
                            pains[j]--;
                            continue out;
                        }
                    }
                }
                ans = Math.min(ow, ow2);
            }
            out.printf("Case #%d: %d%n", loop + 1, ans);

        }
        in.close();
        out.close();
    }
}
