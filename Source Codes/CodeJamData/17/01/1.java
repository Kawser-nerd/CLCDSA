import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCount = in.nextInt();
        next:
        for (int testNo = 1; testNo <= testCount; testNo++) {
            char[] rawPancakes = in.next().toCharArray();
            int n = rawPancakes.length;
            boolean[] pancakes = new boolean[n];
            for (int i = 0; i < n; i++) {
                pancakes[i] = rawPancakes[i] == '+';
            }
            int k = in.nextInt();
            int answer = 0;
            for (int i = 0; i + k <= n; i++) {
                if (!pancakes[i]) {
                    answer++;
                    for (int j = i; j < i + k; j++) {
                        pancakes[j] = !pancakes[j];
                    }
                }
            }
            System.out.print("Case #" + testNo + ": ");
            for (int i = 0; i < n; i++) {
                if (!pancakes[i]) {
                    System.out.println("IMPOSSIBLE");
                    continue next;
                }
            }
            System.out.println(answer);
        }
    }
}
