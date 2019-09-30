import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] imos = new int[2400 / 5 + 1];

        for (int i = 0; i < N; i++) {
            String[] strs = sc.next().split("-");
            int s = (int) Math.floor(Integer.parseInt(strs[0]) / 5.0f);
            int e = (int) Math.ceil(Integer.parseInt(strs[1]) / 5.0f);
            if(String.valueOf(e*5).endsWith("60")) {
                e = (e*5 + 40)/ 5;
            }
            imos[s]++;
            imos[e]--;
        }

        int ss = -1, v = 0;
        for (int i = 0; i < imos.length; i++) {
            v += imos[i];
            if (v > 0 && ss == -1) {
                ss = i;
            } else if (v == 0 && ss != -1) {
                System.out.println(String.format("%04d-%04d", ss * 5, i * 5));
                ss = -1;
            }
        }
    }
}