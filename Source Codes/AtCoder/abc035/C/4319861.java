import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] l = new int[q];
        int[] r = new int[q];
        int[] koma = new int[200100];
        for (int i = 0; i < q; i++) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
            koma[l[i] - 1]++;
            koma[r[i]]++;
        }
        boolean omote = true;
        for (int i = 0; i < n; i++) {
            int pos = koma[i];
            if (pos % 2 == 1) {
                omote = !omote;
            }
            if (omote) {
                System.out.print(0);
            } else {
                System.out.print(1);
            }
        }
        System.out.println();
    }
}