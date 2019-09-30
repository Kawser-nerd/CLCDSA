import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
public class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a   = scan.nextInt();
        Integer b[] = new Integer[a];
        int alicesum = 0;
        int bobsum   = 0;

        for (int i = 0; i < a; i++) {
            b[i] = scan.nextInt();
        }

        Arrays.sort(b, Collections.reverseOrder());

        for (int i = 0; i < a; i = i+2) {
        	alicesum = alicesum + b[i];
        }

        for (int i = 1; i < a; i = i+2) {
        	bobsum = bobsum + b[i];
        }

        System.out.println(alicesum-bobsum);

    }
}