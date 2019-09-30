import java.util.*;

public class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = sc.nextInt();
        }

        int[] cache = new int[n];
        Arrays.fill(cache, -1);

        System.out.println(cost(n - 1, values, cache));
    }

    private static int cost(int i, int[] values, int[] cache) {
        int ans = 0;
        if (cache[i] != -1) {
            return cache[i];
        }
        if (i == 0) {
            ans = 0;
        } else if (i == 1) {
            ans = Math.abs(values[1] - values[0]);
        } else {
            int a = cost( i - 2, values, cache) + Math.abs(values[i] - values[i - 2]);
            int b = cost( i - 1, values, cache) + Math.abs(values[i] - values[i - 1]);
            ans = Math.min(a, b);
        }
        if (cache[i] == -1) {
            cache[i] = ans;
        }
        return ans;
    }

}