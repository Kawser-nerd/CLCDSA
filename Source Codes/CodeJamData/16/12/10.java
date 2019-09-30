package Round1A2016;

import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int testCase = 1; testCase <= T; ++testCase) {
            final int n = sc.nextInt();
            final int[] count = new int[2500 + 1];
            for (int i = 0; i < n * (2 * n - 1); ++i)
                count[sc.nextInt()]++;
            int[] row = new int[n];
            int rowInd = 0;
            for (int i = 0;i < count.length; ++i) {
                if (count[i] % 2 == 1) {
                    row[rowInd++] = i;
                }
            }
            System.out.printf("Case #%d: ", testCase);
            for (int x: row) {
                System.out.print(x + " ");
            }
            System.out.println();
        }
    }
}