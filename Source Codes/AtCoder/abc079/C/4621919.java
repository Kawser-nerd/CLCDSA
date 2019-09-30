import java.util.Scanner;

/**
 * ABC079C_Train_Ticket
 */
public class Main {
    private static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);

        String ABCD = sc.next();
        String[] strArray = ABCD.split("");
        int length = ABCD.length() - 1; // ??????"+"????????????????

        String answer = "";
        int ansNum = 0;
        for (int i = 0; i < (1 << length); i++) {
            // ????1?1????????????????
            answer = strArray[0];
            ansNum = Integer.valueOf(strArray[0]);
            for (int j = 0; j < length; j++) {
                // ???????????????????????
                if ((i >> j) % 2 == 0) {
                    // "-"??????
                    answer += "-" + strArray[j + 1];
                    ansNum -= Integer.valueOf(strArray[j + 1]);
                } else {
                    // "+"??????
                    answer += "+" + strArray[j + 1];
                    ansNum += Integer.valueOf(strArray[j + 1]);
                }
            }
            if (ansNum == 7) {
                answer += "=7";
                break;
            }
        }

        System.out.println(answer);

        sc.close();
    }
}