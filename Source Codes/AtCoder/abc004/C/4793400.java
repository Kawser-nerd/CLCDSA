import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() % 30;
        int[] ar = new int[6];
        for (int i = 0; i < 6; i++) ar[i] = i + 1;
        for (int i = 0; i < n; i++) {
            int tmp = ar[i % 5];
            ar[i % 5] = ar[i % 5 + 1];
            ar[i % 5 + 1] = tmp;
        }
        for (int i = 0; i < 6; i++)
            System.out.print(ar[i]);
        System.out.println();
    }
}