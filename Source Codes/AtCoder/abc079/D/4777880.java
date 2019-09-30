import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();

        int[][] distances = new int[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                distances[i][j] = sc.nextInt();
            }
        }

        int[] nums = new int[10];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int a = sc.nextInt();
                if(a != -1){
                    nums[a]++;
                }
            }
        }

        warshallFloyd(10, distances);

        int ans = 0;
        for(int i = 0; i < 10; i++){
            ans += nums[i] * distances[i][1];
        }

        out.println(ans);
    }

    public static void warshallFloyd(int vertex, int[][] distance) {
        for (int k = 0; k < vertex; k++) {           // ??????
            for (int i = 0; i < vertex; i++) {        // ???????
                for (int j = 0; j < vertex; j++) {   // ??????
                    if (distance[i][j] > distance[i][k] + distance[k][j]) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
    }
}