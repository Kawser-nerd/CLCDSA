import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int D = sc.nextInt();
        int G = sc.nextInt();

        int[] p = new int[D];
        int[] c = new int[D];
        for (int i = 0; i < D; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }

        // ????? or ??????????????????????????????????????
        // ????????????????????
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < 1<<D; i++){
            int ans_tmp = 0;
            int score = 0;

            // ??????????
            for(int j = 0; j < D; j++){
                if((i>>j & 1) == 1){
                    score += 100 * (j + 1) * p[j] + c[j];
                    ans_tmp += p[j];
                }
                // ?????????????
                if(score >= G){
                    ans = Math.min(ans, ans_tmp);
                    continue;
                }
            }

            // ????????????
            for(int j = 0; j < D; j++){
                // ????????????????
                if((i>>j & 1) == 1){ continue; }

                int score_tmp = score;
                int ans_tmp_tmp = ans_tmp;

                for(int k = 0; k < p[j] - 1; k++){
                    score_tmp += 100 * (j + 1);
                    ans_tmp_tmp++;

                    // ?????????????
                    if(score_tmp >= G){
                        ans = Math.min(ans, ans_tmp_tmp);
                        break;
                    }
                }
            }
        }
        out.println(ans);
    }
}