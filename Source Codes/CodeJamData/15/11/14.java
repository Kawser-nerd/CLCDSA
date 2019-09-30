import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int N = sc.nextInt();
            int[] m = new int[N];
            for (int i = 0; i < N; i++) {
                m[i] = sc.nextInt();
            }
            int totalDecrease = 0;
            int maxDecrease = 0;
            for (int i = 1; i < N; i++) {
                if (m[i] < m[i - 1]) {
                    int difference = m[i - 1] - m[i];
                    totalDecrease += difference;
                    maxDecrease = Math.max(maxDecrease, difference);
                }
            }

            int mushrooms = 0;
            for (int i = 0; i < N - 1; i++) {
                mushrooms += Math.min(maxDecrease, m[i]);
            }

            System.out.println("Case #" + caseNum + ": " + totalDecrease + " " + mushrooms);
        }
    }
}
