import java.util.Arrays;
import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            int K = sc.nextInt();
            int N = sc.nextInt();
            int[] keys = new int[201];
            for (int i = 0; i < K; i++) {
                keys[sc.nextInt()]++;
            }

            Chest[] chests = new Chest[N];
            for (int i = 0; i < N; i++) {
                int Ti = sc.nextInt();
                int Ki = sc.nextInt();
                int[] arr = new int[Ki];
                for (int j = 0; j < Ki; j++) {
                    arr[j] = sc.nextInt();
                }
                chests[i] = new Chest(Ti, arr);
            }

            boolean[][] possible = new boolean[(1 << N)][N];
            for (int bitmask = 0; bitmask < (1 << N); bitmask++) {
                int[] remainingKeys = Arrays.copyOf(keys, 201);
                for (int i = 0; i < N; i++) {
                    if ((bitmask & (1 << i)) != 0) {
                        remainingKeys[chests[i].keyToOpen]--;
                        for (int key : chests[i].keys) {
                            remainingKeys[key]++;
                        }
                    }
                }

                for (int i = 0; i < N; i++) {
                    if ((bitmask & (1 << i)) != 0)
                        continue;
                    if (remainingKeys[chests[i].keyToOpen] > 0)
                        possible[bitmask][i] = true;
                }
            }

            boolean[] dp = new boolean[(1 << N)];
            for (int i = 0; i < N; i++) {
                int bitmask = ((1 << N) - 1) ^ (1 << i);
                dp[(1 << N) - 1] |= possible[bitmask][i];
            }
            for (int bitmask = (1 << N) - 2; bitmask >= 0; bitmask--) {
                for (int i = 0; i < N; i++) {
                    if ((bitmask & (1 << i)) != 0 || !possible[bitmask][i])
                        continue;
                    dp[bitmask] |= dp[(bitmask | (1 << i))];
                }
            }

            System.out.print("Case #" + caseNum + ":");
            if (dp[0]) {
                int bitmask = 0;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if ((bitmask & (1 << j)) != 0 || !possible[bitmask][j])
                            continue;
                        if (dp[bitmask | (1 << j)]) {
                            System.out.print(" " + (j + 1));
                            bitmask |= (1 << j);
                            break;
                        }
                    }
                }
            } else {
                System.out.print(" IMPOSSIBLE");
            }
            System.out.println();
        }
    }

    static class Chest {
        int keyToOpen;
        int[] keys;

        public Chest(int keyToOpen, int[] keys) {
            super();
            this.keyToOpen = keyToOpen;
            this.keys = keys;
        }
    }
}
