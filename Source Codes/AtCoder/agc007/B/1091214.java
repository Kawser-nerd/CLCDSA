import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int inv[] = new int[N];
        for (int i = 0; i < N; i++) {
            inv[sc.nextInt()-1] = i;
        }

        for (int i = 0; i < N; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(N * (i + 1));
        }
        System.out.println("");

        for (int i = 0; i < N; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(N * (N - i) + inv[i]);
        }
        System.out.println("");
    }
}