import java.util.Scanner;

/*
 * ?????
 * <input>
 * 5
 * 1 4 1 2 2
 *
 * <correct output>
 * No
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            int a4Cnt = 0;
            int a2Cnt = 0;
            int a1Cnt = 0;
            for (int i = 0; i < n; i++) {
                int a = sc.nextInt();
                if ( a % 4 == 0 ) {
                    a4Cnt++;
                } else if ( a % 2 == 0 ) {
                    a2Cnt++;
                } else {
                    a1Cnt++;
                }
            }

            a1Cnt += a2Cnt % 2;

            if ( a1Cnt > a4Cnt + 1 ) {
                System.out.println("No");
            } else {
                System.out.println("Yes");
            }
        }
    }
}