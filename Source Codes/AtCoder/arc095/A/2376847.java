import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = sc.nextInt();
        }

        int[] org = Arrays.copyOf(arr, arr.length);

        Arrays.sort(arr);
        int mIdx = (arr.length - 1) / 2;

        for (int i = 0; i < org.length; ++i) {
            if (org[i] > arr[mIdx]) {
                System.out.println(arr[mIdx]);
            } else {
                System.out.println(arr[mIdx + 1]);
            }
        }
    }
}