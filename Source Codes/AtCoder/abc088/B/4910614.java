import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }

        Arrays.sort(a);

        int alice = 0;
        int bob = 0;
        boolean isAlice = true;
        for (int i = a.length - 1; i != -1; i--) {
            if (isAlice) {
                alice += a[i];
            } else {
                bob += a[i];
            }
            isAlice = !isAlice;
        }

        System.out.println(alice - bob);
    }
}