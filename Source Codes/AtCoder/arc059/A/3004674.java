import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] str) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int[] arr = new int[N];
        for (int i=0;i<N;i++) arr[i] = scan.nextInt();

        Arrays.sort(arr);
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        for (int i: arr) {
            max = Math.max(max, i);
            min = Math.min(min, i);
        }

        int mincost = Integer.MAX_VALUE;
        for (int i=min;i<=max;i++) {
            int total = 0;
            for (int j: arr) total += (i - j) * (i - j);
            if (total > mincost) break;
            mincost = total;
        }
        System.out.println(mincost);
    }
}