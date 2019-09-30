package round1c;


import java.util.ArrayList;
import java.util.List;

public class ProbA extends Prob{

    void setup() {
        bin = true;
        bout = true;
        in = "A-large.in";
        out = "aout-large.txt";
    }

    @Override
    public void main() {
        setup();
        reDirect();
        int T = scanner.nextInt();
        for (int cas = 1; cas <= T; cas++) {
            double ans = run();
            System.out.println(String.format("Case #%d: %.9f", cas, ans));
        }
    }

    double run() {
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[][] pancake = new int[n][2];
        for (int i = 0; i < n; i++) {
            pancake[i][0] = scanner.nextInt();
            pancake[i][1] = scanner.nextInt();
        }
        double ans = 0;
        for (int i = 0; i < n; i++) {
            double curr = calcSide(pancake[i]) + calcArea(pancake[i][0]);
            List<Double> arr = new ArrayList<>();
            for (int j = 0; j < n; j++) if (j != i) {
                if (pancake[j][0] <= pancake[i][0]) {
                    arr.add(calcSide(pancake[j]));
                }
            }
            if (arr.size() < k -1) {
                continue;
            }
            arr.sort((a, b) -> -Double.compare(a, b));
            for(int j = 0; j < k - 1; j++) {
                curr += arr.get(j);
            }
            if (curr > ans)  {
                ans = curr;
            }
        }
        return ans;
    }

    private double calcSide(int[] pancake) {
        double r = (double)pancake[0];
        double h = (double)pancake[1];
        return 2.0 * r * h * Math.PI;
    }

    private double calcArea(int r) {
        return Math.PI * (double)r * (double)r;
    }

}
