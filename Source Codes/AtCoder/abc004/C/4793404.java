import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();

        int mod30 = n % 30;

        int[] arr = new int[6];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i + 1;
        }

        for (int i = 0; i < mod30; i++) {
            int k = i % 5;
            int tmp = arr[k];
            arr[k] = arr[k + 1];
            arr[k + 1] = tmp;
        }

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
        }
    }

}