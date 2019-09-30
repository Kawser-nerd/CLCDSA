import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] a = new int[n][2];// idx, height
        for (int i = 0; i < n; i++) a[i] = new int[]{i, sc.nextInt()};
        Arrays.sort(a, (x, y) -> y[1] - x[1]);
        for (int i = 0; i < n; i++) System.out.println(a[i][0]+1);

        sc.close();
    }

}