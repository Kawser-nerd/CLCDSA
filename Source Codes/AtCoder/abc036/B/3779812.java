import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        char[][] arr = new char[n][n];

        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < n; j++) {
                arr[i][j] = line.charAt(j);
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = n - 1; i >= 0; i--) {
                System.out.print(arr[i][j]);
            }
            System.out.print("\n");
        }
    }
}