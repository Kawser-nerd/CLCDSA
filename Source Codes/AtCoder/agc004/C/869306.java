import java.util.*;

class Main {
        public static void main(String args[]) {
                Scanner sc = new Scanner(System.in);
                int H = sc.nextInt(), W = sc.nextInt();
                String[] a = new String[H];
                for (int i = 0; i < H; i++) {
                        a[i] = sc.next();
                }
                StringBuilder SB = new StringBuilder(H * (W + 1) * 2 + 1);
                for (int i = 0; i < H; i++) {
                        for (int j = 0; j < W; j++) {
                                if (j != W - 1 && (i % 2 == 0 || j == 0 || a[i].charAt(j) == '#')) {
                                        SB.append('#');
                                } else {
                                        SB.append('.');
                                }
                        }
                        SB.append('\n');
                }
                SB.append('\n');

                for (int i = 0; i < H; i++) {
                        for (int j = 0; j < W; j++) {
                                if (j != 0 && (i % 2 == 1 || j == W - 1 || a[i].charAt(j) == '#')) {
                                        SB.append('#');
                                } else {
                                        SB.append('.');
                                }
                        }
                        SB.append('\n');
                }

                System.out.print(SB);
        }
}