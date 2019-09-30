import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);
    static long nextLong () {return Long.parseLong(sc.next());}

    public static void main(String[] args) {
        int N = sc.nextInt();

        long[][] values = new long[N][3];
        for (int i = 0; i < N; i++) {
            values[i] = new long[] {nextLong(), nextLong(), nextLong()};
        }


        String ans = null;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                int[] centerPosi = new int[]{i, j};

                long H = 0;
                for (int k = 0; k < N; k++) {
                    long x = values[k][0];
                    long y = values[k][1];
                    long h = values[k][2];

                    if (h != 0) {
                        H = h + Math.abs(centerPosi[0] - x) + Math.abs(centerPosi[1] - y);
                        break;
                    }
                }

                boolean isOK = true;
                for (int k = 0; k < N; k++) {
                    long x = values[k][0];
                    long y = values[k][1];
                    long h = values[k][2];

                    long estimatedH = Math.max((H - Math.abs(x - centerPosi[0]) - Math.abs(y - centerPosi[1])), 0);
                    isOK = isOK && (estimatedH == h);
                }
                if (isOK) {
                    ans = i + " " + j + " " + H;
                }
            }
        }
        System.out.println(ans);
    }


}