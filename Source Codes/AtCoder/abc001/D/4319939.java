import java.util.Scanner;

public class Main {

    void run() {

        Scanner sc = new Scanner(System.in);

        int[] range = new int[(60 * 24) + 2];
        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            String[] sp = sc.next().split("-");
            int s = timeToIntB(sp[0]), e = timeToIntA(sp[1]);
//            System.err.println(s + " " + e);
            range[s] += 1;
            range[e + 1] -= 1;
        }

        for (int i = 1; i <= (60 * 24); i++) {
            range[i] += range[i - 1];
        }
        for (int i = 0;i <= (60 * 24);i++) {
            if (range[i] > 0) {
                int s = i;
                int e = i;
                for (;i <= 60 * 24 && range[i] > 0; i++) {
                    e = i;
                }
                System.out.println(intToTime(s) + "-" + intToTime(e));
            }
        }
    }

    int timeToIntB(String time) {
        int h = Integer.parseInt(time.substring(0, 2));
        int m = Integer.parseInt(time.substring(2));
        m = (m / 5) * 5;
        return (h * 60 + m);
    }

    int timeToIntA(String time) {
        int h = Integer.parseInt(time.substring(0, 2));
        int m = Integer.parseInt(time.substring(2));
        m = (m + 4) / 5 * 5;
        return (h * 60 + m);
    }

    String intToTime(int time) {
        int h = (time) / 60;
        int m = (time) % 60;

        return String.format("%02d%02d", h, m);
    }

    public static void main(String[] args) {
        new Main().run();
    }
}