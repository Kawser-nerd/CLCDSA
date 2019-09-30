import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] line = scanner.nextLine().split(" ", n);

        int[] arr = new int[n];
        int total = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(line[i]);
            total += arr[i];
        }

        if (total % n != 0) {
            System.out.println(-1);
            return;
        }

        int bridges = 0;
        int avg = total / n;
        int currentTotal = 0;
        int currentSize = 0;
        for (int i = 0; i < n; i++) {
            if ((currentTotal + arr[i]) == avg * (currentSize + 1)) {
                currentTotal = 0;
                currentSize = 0;
            } else {
                currentTotal += arr[i];
                currentSize++;
                bridges++;
            }
        }
        System.out.println(bridges);
    }
}