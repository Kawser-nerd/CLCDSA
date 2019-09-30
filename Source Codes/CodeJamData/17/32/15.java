package round1c;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ProbBB extends Prob{

    void setup() {
        bin = true;
        bout = true;
        in = "B-large.in";
        out = "bout_large.txt";
    }

    @Override
    public void main() {
        setup();
        reDirect();
        int T = scanner.nextInt();
        for (int cas = 1; cas <= T; cas++) {
            int ans = run();
            System.out.println(String.format("Case #%d: %d", cas, ans));
        }
    }

    int run() {
        int ac = scanner.nextInt();
        int aj = scanner.nextInt();
        int[][] all = new int[ac+aj][3];
        int n = ac + aj;
        int cc = 0;
        for (int i = 0; i < ac; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            all[cc][0] = start;
            all[cc][1] = end;
            all[cc][2] = 0;
            cc++;
        }
        for (int i = 0; i < aj; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            all[cc][0] = start;
            all[cc][1] = end;
            all[cc][2] = 1;
            cc++;
        }
        Arrays.sort(all, (a, b) -> Integer.compare(a[0], b[0]));
        List<Integer> ablk = new ArrayList<>();
        List<Integer> bblk = new ArrayList<>();
        int ans = 0;
        int[] tot = new int[3];
        for (int i = 0; i < n; i++) {
            tot[all[i][2]] += all[i][1] - all[i][0];
            int gap = (all[i][0] + 1440 - all[(i + n - 1) % n][1]) % 1440;
            if (all[i][2] != all[(i + n - 1) % n][2]) {
                tot[2] += gap;
                ans += 1;
            }
            else {
                tot[all[i][2]] += gap;
                if (all[i][2] == 0) ablk.add(gap);
                else bblk.add(gap);
            }
        }
        ablk.sort((a,b) -> -Integer.compare(a, b));
        bblk.sort((a,b) -> -Integer.compare(a, b));
        if (tot[0] <= 720 && tot[1] <= 720) {
            return ans;
        }
        List<Integer> blk = null;
        int totv = 0;
        if (tot[0] > 720) {totv = tot[0]; blk = ablk;}
        else {totv = tot[1]; blk = bblk;}

        for (int i = 0; i < blk.size(); i++) {
            if (totv > 720) {
                totv -= blk.get(i);
                ans += 2;
            }
            else {
                break;
            }
        }
        return ans;
    }
}
