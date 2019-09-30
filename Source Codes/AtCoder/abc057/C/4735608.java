import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();

        // ???N * ???N????????
        long divide1 = (long) Math.sqrt(N);

        while(N % divide1 != 0) {
            divide1--;
        }
        long divide2 = N / divide1;

        int len1 = String.valueOf(divide1).length();
        int len2 = String.valueOf(divide2).length();

        out.println(Math.max(len1, len2));
    }
}