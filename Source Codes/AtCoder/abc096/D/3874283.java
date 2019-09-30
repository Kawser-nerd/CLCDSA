import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        a[0] = 11;
        System.out.print(a[0] + " ");
        for (int i = 1; i < n; i++) {
            for (int j = a[i - 1] + 1; j < 55555; j++) {
                if (isPrime(j)) {
                    if (j % 5 == 1) {
                        a[i] = j;
                        System.out.print(j + " ");
                        break;
                    }
                }
            }
        }
        System.out.println();
    }

    public static boolean isPrime(int num) {
        if (num < 2)
            return false;
        else if (num == 2)
            return true;
        else if (num % 2 == 0)
            return false; // ??????????

        double sqrtNum = Math.sqrt(num);
        for (int i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) {
                // ??????
                return false;
            }
        }

        // ?????
        return true;
    }
}