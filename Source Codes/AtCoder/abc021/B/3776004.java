import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = Integer.parseInt(scanner.nextLine());
        String[] line = scanner.nextLine().split(" ", 2);
        int a = Integer.parseInt(line[0]);
        int b = Integer.parseInt(line[1]);

        boolean[] passed = new boolean[n];
        passed[a-1] = true;
        passed[b-1] = true;

        int k = Integer.parseInt(scanner.nextLine());
        line = scanner.nextLine().split(" ", k);
        boolean yes = true;
        for (int i = 0; i < k; i++) {
            int p = Integer.parseInt(line[i]);
            if (passed[p-1]) {
                yes = false;
                break;
            }
            passed[p-1] = true;
        }

        if (yes) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}