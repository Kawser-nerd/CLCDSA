import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        int x = sc.nextInt();
        int a[] = new int[n];
        int sum = x;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            sum += 1 + (d - 1) / a[i];
        }
        System.out.println(sum);
    }
}