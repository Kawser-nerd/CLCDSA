import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] edges = new int[N];
        int sum = 0;
        int max = 0;
        for (int i = 0; i < N; i++) {
            edges[i] = sc.nextInt();
            sum += edges[i];
            max = Math.max(max, edges[i]);
        }
        System.out.println(max < (sum - max) ? "Yes" : "No");
    }
}