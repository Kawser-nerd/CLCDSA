import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int min = 0;
        for (int i = 1; i < n; i++) {
            String[] a = String.valueOf(i).split("");
            String[] b = String.valueOf(n - i).split("");
            int sum = 0;
            for (int j = 0; j < a.length; j++) {
                sum += Integer.parseInt(a[j]);
            }
            for (int j = 0; j < b.length; j++) {
                sum += Integer.parseInt(b[j]);
            }
            if (i == 1 || min > sum) {
                min = sum;
            }
        }
        System.out.println(min);
    }

}