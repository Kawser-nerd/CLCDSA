import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    int a, b, c, d, e, f;
    private ArrayList<Integer> listW, listS;

    public static void main(String[] args) {
        Main m = new Main();
        m.read();
        m.solve();
    }

    private void read() {
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt();
        e = sc.nextInt();
        f = sc.nextInt();
        listW = new ArrayList<>();
        listS = new ArrayList<>();
    }

    private double calc(int a, int b) {
        return (double) (100 * b) / (a + b);
    }

    private void solve() {
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < f; j++) {
                int w = a * i + b * j;
                w *= 100;
                if (w != 0 && w < f) {
                    listW.add(w);
                }
            }
        }
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < f; j++) {
                int s = c * i + d * j;
                if (s < f)
                    listS.add(s);
            }
        }
        double rate = -1.;
        int ansS = -1, ansW = -1;
        for (int w: listW) {
            for (int s : listS) {
                if (w + s <= f && s <= (w / 100) * e) {
                    double tmp = calc(w, s);
                    if (rate < tmp) {
                        ansS = s;
                        ansW = w;
                        rate = tmp;
                    }
                }
            }
        }
        System.out.printf("%d %d\n", (ansS + ansW), ansS);
    }


}