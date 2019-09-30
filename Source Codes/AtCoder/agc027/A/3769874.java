import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        Arrays.sort(a);

        int happy = 0;

        for (int j = 0; j < n; j++) {
            x = x - a[j];
            if (x < 0) {
                break;
            } else {
                happy++;
            }
        }
        if (x > 0) {
            happy--;
        }

        System.out.println(happy);
    }

}