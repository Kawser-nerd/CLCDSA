import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());

        int[] ng = new int[3];
        ng[0] = Integer.parseInt(scanner.nextLine());
        ng[1] = Integer.parseInt(scanner.nextLine());
        ng[2] = Integer.parseInt(scanner.nextLine());

		int[] minMoves = new int[n+1];
		Arrays.fill(minMoves, 1000);
        minMoves[n] = 0;

        for (int i = n; i >= 0; i--) {
            if (i == ng[0] || i == ng[1] || i == ng[2]) continue;

            for (int j = 1; j <= 3; j++) {
                if (i - j >= 0) {
                    minMoves[i - j] = Math.min(minMoves[i] + 1, minMoves[i - j]);
                }
            }
        }

        if (minMoves[0] <= 100) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}