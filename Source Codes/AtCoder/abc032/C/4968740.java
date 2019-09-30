import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String[] nk = sc.nextLine().split(" ");
        int n = Integer.parseInt(nk[0]);
        int k = Integer.parseInt(nk[1]);
        int[] s = new int[n];

        for (int i = 0; i < n; i++) {
            s[i] = Integer.parseInt(sc.nextLine());

            if (s[i] == 0) {
                System.out.println(n);
                return;
            }
        }

        int right = 0;
        long product = 1;
        int answer = 0;
        for (int left = 0; left < n; left++) {


            while (right < n && product * s[right] <= k) {
                product *= s[right];
                right++;
            }

            if (right - left > answer) {
                answer = right - left;
            }

            if (left == right) {
                right++;
            } else {
                product /= s[left];
            }

        }

        System.out.println(answer);
    }
}