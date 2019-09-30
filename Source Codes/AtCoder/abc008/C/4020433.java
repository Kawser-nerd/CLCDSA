import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(scanner.nextLine());
        }

        int[] numDivider = new int[n];
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && arr[i] % arr[j] == 0) {
                    num++;
                }
            }
            numDivider[i] = num;
        }

        double result = 0.0;
        for (int i = 0; i < n; i++) {
            if (numDivider[i] % 2 == 0) {
                result += (double)(numDivider[i] + 2) / (double)(2 * numDivider[i] + 2);
            } else {
                result += 0.5;
            }
        }
        System.out.println(result);
    }
}