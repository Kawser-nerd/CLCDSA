import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int K = sc.nextInt();
            int C = sc.nextInt();
            int S = sc.nextInt();

            System.out.print("Case #" + caseNum + ":");
            if (C * S < K) {
                System.out.println(" IMPOSSIBLE");
                continue;
            }
            for (int i = 0; i < K; i += C) {
                long index = 0;
                for (int j = i; j < i + C; j++) {
                    index = index * K + Math.min(j, K - 1);
                }
                System.out.print(" " + (index + 1));
            }
            System.out.println();
        }
    }
}
