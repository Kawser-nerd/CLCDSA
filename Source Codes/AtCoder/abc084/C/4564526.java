import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] cs = new int[N-1];
        int[] ss = new int[N-1];
        int[] fs = new int[N-1];

        for (int i = 0; i < N-1; i++) {
            cs[i] = sc.nextInt();
            ss[i] = sc.nextInt();
            fs[i] = sc.nextInt();
        }

        for (int i = 0; i < N - 1; i++) {
            int t = 0;
            for (int j = i; j < N - 1; j++) {
                if (i == j) {
                    t = cs[j] + ss[j];
                } else {
                    if (t > ss[j]) {
                        int k = ((t - ss[j]) + fs[j] - 1) / fs[j];
                        t = ss[j] + fs[j] * k + cs[j];
                    } else {
                        t = ss[j] + cs[j];
                    }
                }
            }
            System.out.println(t);
        }
        System.out.println("0");
    }
}