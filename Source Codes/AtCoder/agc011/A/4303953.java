import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();
        int k = sc.nextInt();
        int[] t = new int[n];
        for (int i = 0 ; i < n ; i++) {
            t[i] = sc.nextInt();
        }
        Arrays.sort(t);
        int bus = 0;
        int pass = 0;
        int time = 0;
        for (int i = 0 ; i < n ; i++) {
            if (time == 0) {
                time = t[i];
            }
            if (t[i] - time > k) {
                bus++;
                pass = 1;
                time = t[i];
            } else {
                pass++;
                if (pass == c) {
                    bus++;
                    pass = 0;
                    time = 0;
                }
            }


        }

        if (pass > 0) {
            bus++;
        }

        System.out.println(bus);

    }

}