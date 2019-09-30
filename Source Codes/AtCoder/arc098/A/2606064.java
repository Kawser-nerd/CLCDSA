import java.util.Scanner;

/**
 * Solution for AtCoder Regular Contest 098.
 * Problems are available at: https://arc098.contest.atcoder.jp/tasks/arc098_a
 */
public class Main {

    public static int findMinTurns(int n, String s) {

        int eastTotal = 0;
        int westTotal = 0;

        for (char ch : s.toCharArray()) {
            if (ch == 'E') {
                eastTotal++;
            } else if (ch == 'W') {
                westTotal++;
            }
        }

        int eastPassed = 0;
        int westPassed = 0;

        int currentTurns;
        int leastTurns = n;

        for (char ch : s.toCharArray()) {
            currentTurns = westPassed + eastTotal - eastPassed;

            if (ch == 'E') {
                currentTurns--;
                eastPassed++;

            } else if (ch == 'W') {
                westPassed++;
            }

            if (currentTurns < leastTurns) {
                leastTurns = currentTurns;
            }
        }
        return leastTurns;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        String s = sc.nextLine();
        System.out.println(findMinTurns(n, s));

        sc.close();

    }
}