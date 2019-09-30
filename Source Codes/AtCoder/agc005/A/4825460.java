import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();

        int stNum = 0;
        int sNum = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == 'S') {
                sNum++;
            } else {
                if (sNum > 0) {
                    sNum--;
                    stNum++;
                }
            }
        }
        out.println(str.length() - stNum * 2);
    }
}