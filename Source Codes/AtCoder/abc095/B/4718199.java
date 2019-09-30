import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] m = new int[n];

        int sumG = 0;
        int minDonut = 1001;

        for (int i = 0; i < n; i++) {
            m[i] = sc.nextInt();
            sumG += m[i];
            minDonut = Math.min(minDonut, m[i]);
        }

        int sumDonut = n + (x - sumG) / minDonut;
        System.out.println(sumDonut);
    }
}