import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] c = sc.next().toCharArray();
        int[] a = new int[4];
        for (int i = 0 ; i < c.length ; i++) {
            if (c[i] == 'N') {
                a[0]++;
            } else if (c[i] == 'W') {
                a[1]++;
            } else if (c[i] == 'S') {
                a[2]++;
            } else {
                a[3]++;
            }
        }

        if (a[0] == 0 && a[2] != 0) {
            System.out.println("No");
            return;
        }
        if (a[1] == 0 && a[3] != 0) {
            System.out.println("No");
            return;
        }
        if (a[2] == 0 && a[0] != 0) {
            System.out.println("No");
            return;
        }
        if (a[3] == 0 && a[1] != 0) {
            System.out.println("No");
            return;
        }
        System.out.println("Yes");
    }

}