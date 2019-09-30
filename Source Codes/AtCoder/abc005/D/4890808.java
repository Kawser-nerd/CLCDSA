import java.util.*;

public class Main {

    static Long[] aArr;
    static Long[] bArr;
    static Long[] cArr;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[][] d = new int[n + 1][n + 1];

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                d[i][j] = sc.nextInt();
            }
        }

        int q = sc.nextInt();
        int[] p = new int[q];
        for (int i = 0; i < q; i++) {
            p[i] = sc.nextInt();
        }

        int[][] cumSum = new int[n + 1][n + 1];

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                cumSum[i][j] = cumSum[i - 1][j] + cumSum[i][j - 1] - cumSum[i - 1][j - 1] + d[i][j];
            }
        }

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int i2 = 0; i2 < n; i2++) {
                for (int j = i + 1; j < n + 1; j++) {
                    for (int j2 = i2 + 1; j2 < n + 1; j2++) {
                        int key = (j2 - i2) * (j - i);
                        map.put(key, Math.max(map.getOrDefault(key, 0), cumSum[j][j2] - cumSum[i][j2] - cumSum[j][i2] + cumSum[i][i2]));
                    }
                }
            }
        }
        
        for (int i = 0; i < q; i++) {
            int max = 0;
            for (int k : map.keySet()) {
                if (k <= p[i]) {
                    max = Math.max(map.get(k), max);
                }
            }
            System.out.println(max);
        }

    }

    static void debug(Object... os) {
        System.err.println(Arrays.deepToString(os));
    }


}