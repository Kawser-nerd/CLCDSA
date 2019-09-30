import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String N = sc.next();

        int[] arr = new int[N.length()];
        int max = 0;
        for (int i = 0; i < N.length(); i++) {
            arr[i] = N.charAt(i) - '0';
            max += arr[i];
        }

        for (int i = 0; i < arr.length && arr[i] != 0; i++) {
            int tmp = 0;
            for (int j = 0; j < arr.length; j++) {
                if (i == j) {
                    tmp += arr[j] - 1 + (arr.length - j - 1) * 9;
                    break;
                } else {
                    tmp += arr[j];
                }
            }
            max = Math.max(max, tmp);
        }

        out.println(max);
    }
}