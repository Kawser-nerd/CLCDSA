import org.specs2.internal.scalaz.Comp;
import sun.util.resources.CurrencyNames_th_TH;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class C {


    private static class Meal implements Comparable<Meal> {
        private final int p;
        private final int s;

        public Meal(int p, int s) {
            this.p = p;
            this.s = s;
        }

        public int compareTo(Meal that) {
            return this.p - that.p;
        }
    }

    private String solve() throws IOException {
        int m = nextInt();
        int f = nextInt();
        int n = nextInt();
        Meal[] meals = new Meal[n];
        for (int i = 0; i < n; i++) {
            meals[i] = new Meal(nextInt(), nextInt());
        }
        Arrays.sort(meals);
        int[] d = new int[2000111];
        Arrays.fill(d, -1);
        d[0] = m;
        int ans = 0;
        for (int day = 0; day < d.length; day++) {
            int money = d[day];
            if (money >= 0) {
                ans = Math.max(ans, day);
            }
            int daysMore = 0;
            money -= f;
            for (Meal meal : meals) {
                if (meal.s >= daysMore && meal.p <= money) {
                    int cnt = money / meal.p;
                    cnt = Math.min(cnt, meal.s - daysMore + 1);
                    daysMore += cnt;
                    money -= meal.p * cnt;
                    d[day + daysMore] = Math.max(d[day + daysMore], money);
                }
            }
            /*
            for (int k = day + 1; k < d.length; k++) {
                // need for k days
                int money = d[day];
                if (money >= 0) {
                    ans = Math.max(ans, day);
                }
                money -= f;
                if (money > 0) {
                    int daysCovered = 0;
                    for (Meal meal : meals) {
                        if (meal.s >= daysCovered) {
                            int cnt = Math.min(money / meal.p, meal.s - daysCovered + 1);
                            cnt = Math.min(cnt, k - day - daysCovered);
                            if (cnt > 0) {
                                money -= cnt * meal.p;
                                daysCovered += cnt;
                                if (money == 0 || daysCovered + day >= k) {
                                    break;
                                }
                            }
                        }
                    }
                    if (daysCovered + day >= k) {
                        d[k] = Math.max(d[k], money);
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            */
        }

        return "" + ans;
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
//        String problem = "C-small";
        String problem = "C-small-attempt1";
        reader = new BufferedReader(new FileReader(problem + ".in"));
        PrintWriter writer = new PrintWriter(new File(problem + ".out"));
        try {
            int n = nextInt();
            for (int tc = 1; tc <= n; tc++) {
                writer.print("Case #" + tc + ": ");
                writer.println(solve());
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new C().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}