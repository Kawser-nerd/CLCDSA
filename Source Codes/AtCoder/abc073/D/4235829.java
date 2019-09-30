import java.util.*;

import static java.lang.System.*;

// https://atcoder.jp/contests/abc073/tasks/abc073_d
// ?????????? O(n^3) n?????200 -> 8,000,000(10^6)
// ?????????????????????R!?R?????8 -> 40,320
public class Main {
    final static int INF = 100000000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int R = sc.nextInt();

        int[] r = new int[R];
        for (int i = 0; i < R; i++) r[i] = sc.nextInt() - 1;

        int[] A = new int[M];
        int[] B = new int[M];
        int[] C = new int[M];

        int[][] distance = new int[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++) {
                distance[i][j] = INF;
            }
        }

        for (int i =0; i < M; i++){
            A[i] = sc.nextInt() - 1;
            B[i] = sc.nextInt() - 1;
            C[i] = sc.nextInt();
            distance[A[i]][B[i]] = C[i];
            distance[B[i]][A[i]] = C[i];
        }

        solver(N, r, distance);
    }

    public static void solver(int N, int[] r, int[][] distance) {
        //for(int i = 0; i < N; i++){
        //    out.println(Arrays.toString(distance[i]));
        //}

        // ???????????
        warshallFloyd(N, distance);

        //for(int i = 0; i < N; i++){
        //    out.println(Arrays.toString(distance[i]));
        //}

        // ??????
        Arrays.sort(r);

        int minimumCost = Integer.MAX_VALUE;
        do{
            int cost = 0;
            for(int i = 0; i < r.length - 1; i++){
               cost += distance[r[i]] [r[i+1]];
            }
           minimumCost = Math.min(minimumCost, cost);
        } while(nextPermutation(r));

        out.println(minimumCost);
    }

    public static void warshallFloyd(int vertex, int[][] distance){
        for(int k = 0; k < vertex; k++) {           // ??????
            for(int i = 0; i < vertex; i++){        // ???????
                for(int j = 0; j < vertex; j++ ){   // ??????
                    if(distance[i][j] > distance[i][k] + distance[k][j]){
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
    }

    // http://d.hatena.ne.jp/tomerun/20081203/1228321480
    // ???
    public static boolean nextPermutation(int[] a) {
        for (int i = a.length - 1; i > 0; --i) {
            if (a[i - 1] < a[i]) {
                int swapIndex = find(a[i - 1], a, i, a.length - 1);
                int temp = a[swapIndex];
                a[swapIndex] = a[i - 1];
                a[i - 1] = temp;
                Arrays.sort(a, i, a.length);
                return true;
            }
        }
        return false;
    }

    // dest??????????????????????????????
    private static int find(int dest, int[] a, int s, int e) {
        if (s == e) {
            return s;
        }
        int m = (s + e + 1) / 2;
        return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
    }
}