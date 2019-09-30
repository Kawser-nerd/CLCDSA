import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long H = sc.nextLong();
        long A = sc.nextLong();
        long B = sc.nextLong();
        long C = sc.nextLong();
        long D = sc.nextLong();
        long E = sc.nextLong();

        // N???????????????
        long needH = N * E - H;

        // ????????????????????????
        B += E;
        D += E;

        long cost = Long.MAX_VALUE;
        for (int aNum = 0; ; aNum++) {
            long aCost = A * aNum;
            long tmpNeedH = needH - B * aNum;

            if (tmpNeedH < 0) {
                cost = Math.min(cost, aCost);
                break;
            }

            long cNum = (long) Math.ceil((double) tmpNeedH / D);
            if (tmpNeedH % D == 0) {
                cNum++;
            }
            cost = Math.min(cost, aCost + cNum * C);
        }
        out.println(cost);
    }
}