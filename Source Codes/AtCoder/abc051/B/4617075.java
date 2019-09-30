import java.util.Scanner;

/**
 * ABC051B_Sum_of_Three_Integers
 */
public class Main {
    private static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);

        int K = sc.nextInt();
        int S = sc.nextInt();

        // 1????????????S?????????????
        int answer = 0;

        // ?????????1????????????
        for (int i = 0; i <= K; i++) {
            for (int j = 0; j <= K; j++) {
                if (0 <= S - (i + j) && S - (i + j) <= K) {
                    // for????0???K???2??????????????1?????
                    answer++;
                }
            }
        }

        System.out.println(answer);

        sc.close();
    }
}