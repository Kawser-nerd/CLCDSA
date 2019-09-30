import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] mass = new int[n+1];

        for (int i = 0; i < q; i++) {
            int l = sc.nextInt() - 1;
            int r = sc.nextInt();
            mass[l]++;
            mass[r]--;
        }

        for (int i = 0; i < n; i++) {
            if (i > 0)
                mass[i] += mass[i-1];
            System.out.print(mass[i] % 2);
        }
        System.out.println();
    }
}