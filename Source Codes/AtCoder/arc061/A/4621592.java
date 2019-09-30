import java.util.Scanner;

/**
 * ARC061C_Many_Formulas
 */
public class Main {
    private static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);

        String S = sc.next();

        int length = S.length() - 1; // ??????"+"????????????????
        int tmp = 0;
        long answer = 0;
        for (int i = 0; i < (1 << length); i++) {
            // ????1?1????????????????
            tmp = 0;
            for (int j = 0; j < length; j++) {
                // ???????????????????????
                // 0????????1??+????????????
                if ((i >> j) % 2 == 1) {
                    // "+"??????
                    answer += Long.parseLong(S.substring(tmp, j + 1));
                    tmp = j + 1; // ?????????
                }
            }
            // ???????????????
            answer += Long.parseLong(S.substring(tmp));
        }

        System.out.println(answer);

        sc.close();
    }
}