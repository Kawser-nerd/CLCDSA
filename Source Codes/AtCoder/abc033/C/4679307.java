import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();

        int count = 0;
        int i = 0;
        while (i < S.length()) {
            // ??'+'???0??????
            boolean flag = false;
            while (i < S.length() && S.charAt(i) != '+') {
                if (S.charAt(i) == '0') {
                    flag = true;
                }
                i++;
            }
            i++;

            if (flag != true) {
                count++;
            }

        }

        out.println(count);
    }
}