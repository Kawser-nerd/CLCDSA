import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String ABCD = sc.next();

        int[] nums = new int[4];
        for (int i = 0; i < ABCD.length(); i++) {
            nums[i] = Character.getNumericValue(ABCD.charAt(i));
        }

        int bits = 0;
        for (int i = 0; i < 1 << 3; i++) {
            int tmp = nums[0];
            for (int j = 0; j < 3; j++) {
                if ((i >> j & 1) == 1) {  // '+'
                    tmp += nums[j + 1];
                } else {
                    tmp -= nums[j + 1];
                }
            }

            if (tmp == 7) {
                bits = i;
            }
        }

        StringBuilder str = new StringBuilder();
        str.append(ABCD.charAt(0));
        for (int j = 0; j < 3; j++) {
            if ((bits >> j & 1) == 1) {  // '+'
                str.append("+");
            } else {
                str.append("-");
            }
            str.append(ABCD.charAt(j + 1));
        }
        str.append("=7");

        out.println(str.toString());
    }
}