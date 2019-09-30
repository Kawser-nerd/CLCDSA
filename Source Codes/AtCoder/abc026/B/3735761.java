import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());

        Integer[] arr = new Integer[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(scanner.nextLine());
        }
        Arrays.sort(arr, Comparator.reverseOrder());

        double result = 0.0;
        for (int i = 0; i < n; i++) {
            double area = arr[i] * arr[i] * Math.PI;
            if (i % 2 == 0) {
                result += area;
            } else {
                result -= area;
            }
        }
        System.out.println(result);
    }
}