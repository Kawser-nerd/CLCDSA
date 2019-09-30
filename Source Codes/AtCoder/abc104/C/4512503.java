// ?? -> ?? #4178631

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int d = sc.nextInt();
        int g = sc.nextInt();
        int[] p = new int[d];
        int[] c = new int[d];

        for (int i = 0; i < d; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }

        System.out.println(dfs(p, c, g, 0, 0, 0, new boolean[d]));
    }

    // ??(p, c, g, score:??????, cnt:?????????, point:????????, isCheck:??????)
    static int dfs(int[] p, int[] c, int g, int score, int cnt, int point, boolean[] isCheck) {
        int min = 100000;

        for (int i = 0; i < p.length; i++) {
            if (isCheck[i])     // ???????????????
                continue;

            int needScore = g - score;      // ????????
            int num = (i + 1) * 100;    // ???????
            // ?????????????????????
            int needNum = needScore / num + (needScore % num == 0 ? 0 : 1);

            // ??????????????????????????
            if (needNum <= p[i]) {
                min = Math.min(min, cnt + needNum);
            }
            // ?????????????????????????????????
            else if (num * p[i] + c[i] >= needScore) {
                min = Math.min(min, cnt + p[i]);
            }
            // ???????
            else {
                isCheck[i] = true;
                min = Math.min(min, dfs(p, c, g, score + num * p[i] + c[i], cnt + p[i], i+1, isCheck));
                isCheck[i] = false;
            }
        }

        return min;
    }
}