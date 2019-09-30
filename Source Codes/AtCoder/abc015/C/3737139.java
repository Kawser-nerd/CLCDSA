import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        new Main().main();
    }

    public void main() {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ", 2);
        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);

        int[][] problems = new int[n][k];
        for (int i = 0; i < n; i++) {
            line = scanner.nextLine().split(" ", k);
            for (int j = 0; j < k; j++) {
                problems[i][j] = Integer.parseInt(line[j]);
            }
        }

        int last = 1;
        for (int i = 0; i < n; i++) {
            last *= k;
        }

        boolean found = false;
        for (int selection = 0; selection < last; selection++) {
            int xor = 0;
            int iPowKprev = 1;
            int iPowK = 1;
            for (int i = 0; i < n; i++) {
                iPowK *= k;
                int j = (selection % iPowK) / iPowKprev;
                xor ^= problems[i][j];
                iPowKprev = iPowK;
            }
            if (xor == 0) {
                found = true;
                break;
            }
        }

        if (found) {
            System.out.println("Found");
        } else {
            System.out.println("Nothing");
        }
    }
}