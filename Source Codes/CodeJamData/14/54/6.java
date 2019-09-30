package round3;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class D {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round3/D-sample.in"), System.out);
        io = new Kattio(new FileInputStream("round3/D-small-0.in"), new FileOutputStream("round3/D-small-0.out"));
//        io = new Kattio(new FileInputStream("round3/D-large-0.in"), new FileOutputStream("round3/D-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new D().solve(io);
        }
        io.close();
    }

    int coins[];

    List<List<Integer>> edges;

    // Count max score if I'm at at some node and way toward opponent is cut off
    // Doesn't include coins at this node
    private int maxTreeScore(int node, Set<Integer> nodesGone, int prev, int coinGone) {
        int max = 0;
        for (Integer v : this.edges.get(node)) {
            if (!nodesGone.contains(v) && v != prev) {
                int t = maxTreeScore(v, nodesGone, node, coinGone);
                if (v != coinGone)
                    t += this.coins[v];
                max = Math.max(t, max);
            }
        }
        return max;
    }

    private void solve(Kattio io) {
        int N = io.getInt();
        coins = new int[N];
        edges = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            coins[i] = io.getInt();
            edges.add(new ArrayList<Integer>());
        }
        for (int i = 0; i < N-1; i++) {
            int e = io.getInt() - 1;
            edges.get(i).add(e);
            edges.get(e).add(i);
        }

        int best = Integer.MIN_VALUE;

        for (int a = 0; a < N; a++) {
            ArrayList<Integer> path = new ArrayList<>();
            int score = go(a, path, -1);
            best = Math.max(best, score);
        }

        io.println(best);
    }

    private int go(int cur, ArrayList<Integer> path, int prev) {
        path.add(cur);
        int ascore = coins[path.get(0)];
        int bscore = path.size() == 1 ? 0 : coins[path.get(path.size() - 1)];
        int best = solve(path, 0, path.size() - 1, ascore, bscore);
//        System.out.println(path + " " + ascore + " " + bscore + " => " + best);
        for (Integer v : this.edges.get(cur)) {
            if (v != prev) {
                best = Math.min(best, go(v, path, cur));
            }
        }
        path.remove(path.size() - 1);
        return best;
    }

    private int solve(List<Integer> path, int apos, int bpos, int ascore, int bscore) {
        if (apos == bpos) {
            int a = path.get(apos);
            int prev = apos > 0 ? path.get(apos - 1) : -1;
            int next = apos + 1 < path.size() ? path.get(apos + 1) : -1;
            int best = Integer.MIN_VALUE;
            for (int v : this.edges.get(a)) {
                if (v == prev || v == next) continue;
                HashSet<Integer> gone = new HashSet<>();
                if (prev >= 0) gone.add(prev);
                if (next >= 0) gone.add(next);
                int finalAScore = ascore + this.coins[v] + maxTreeScore(v, gone, a, -1);
                gone.add(v);
                int finalBScore = bscore + maxTreeScore(a, gone, -1, -1);
                best = Math.max(best, finalAScore - finalBScore);
            }
            if (best == Integer.MIN_VALUE) best = ascore - bscore;
            return best;
        }


        int a = path.get(apos), b = path.get(bpos);
        int prevapos = apos < bpos ? apos - 1 : apos + 1;
        int prevbpos = apos < bpos ? bpos + 1 : bpos - 1;
        int nextapos = apos < bpos ? apos + 1 : apos - 1;
        int preva = prevapos >= 0 && prevapos < path.size() ? path.get(prevapos) : -1;
        int prevb = prevbpos >= 0 && prevbpos < path.size() ? path.get(prevbpos) : -1;
        int nexta = nextapos >= 0 && nextapos < path.size() ? path.get(nextapos) : -1;

        int best = Integer.MIN_VALUE;

        // a makes a move away from b
        for (int v : this.edges.get(a)) {
            if (v == preva) continue; // already been here
            if (v == nexta) continue; // this is toward b
            int finalAScore = ascore + this.coins[v] + maxTreeScore(v, new HashSet<Integer>(), a, -1);
            HashSet<Integer> gone = new HashSet<>();
            gone.add(v);
            if (preva >= 0) gone.add(preva);
            int finalBScore = bscore + maxTreeScore(b, gone, prevb, a);
            best = Math.max(best, finalAScore - finalBScore);
        }

        // a makes a move toward b
        ascore += (nextapos == bpos ? 0 : coins[nexta]);
        int score = -solve(path, bpos, nextapos, bscore, ascore);
        best = Math.max(best, score);
        return best;
    }

}
