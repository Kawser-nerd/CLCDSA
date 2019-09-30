import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // 1??????1
        int n = Integer.parseInt(scanner.nextLine());
        if (n == 1) {
            System.out.println(1);
            System.exit(0);
        }
        int[] a = new int[n];

        int i = 0;
        for (String ai: scanner.nextLine().split(" ")) {
            a[i++] = Integer.parseInt(ai);
        }

        int x = 1;
        int plus = 0;

        for (i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                if (plus == -1) {
                    x++;
                    plus = 0;
                } else if (plus == 0) {
                    plus = 1;
                }
            } else if (a[i] < a[i + 1]) {
                if (plus == 1) {
                    x++;
                    plus = 0;
                } else if (plus == 0){
                    plus = -1;
                }
            }
        }

        System.out.println(x);
    }
}