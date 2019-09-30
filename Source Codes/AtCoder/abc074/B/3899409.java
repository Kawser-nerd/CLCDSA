import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        int k = Integer.parseInt(scanner.nextLine());
        String[] line = scanner.nextLine().split(" ", n);

        int result = 0;
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(line[i]);
            result += 2 * Math.min(x, k - x);
        }
        System.out.println(result);
    }
}