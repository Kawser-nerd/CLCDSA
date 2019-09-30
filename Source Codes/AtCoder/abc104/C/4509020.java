import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int D = sc.nextInt();
        int G = sc.nextInt();

        int[] p = new int[D];
        int[] c = new int[D];

        for (int i = 0; i < D; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }

        int ans = Integer.MAX_VALUE;
        for (int mask = 0; mask < (1 << D); mask++) {//D??2?????
            int sum = 0, num = 0, restMax = -1;
            for (int i = 0; i < D; i++) {
                if (((mask >> i) & 1) == 1) {
                    // ??????????????
                    sum += 100 * (i + 1) * p[i] + c[i];
                    num += p[i];
                } else {
                    // ????????????????????????
                    // ????????????????(=?????0??)
                    restMax = i;
                }
            }

            //??????????????
            if (sum < G && restMax != -1) {
                // ??????????????????????
                int point = 100 * (restMax + 1);
                //???????
                int rest = (G - sum);
                int need = (rest + (point - 1)) / point;
                if (need >= p[restMax]) {
                    // ????????,?????????
                    continue;
                }
                num += need;
            }
            ans = Math.min(ans, num);
        }

        System.out.println(ans);
    }
}