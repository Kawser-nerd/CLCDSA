package round3;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class B {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round3/B-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("round3/B-small-0.in"), new FileOutputStream("round3/B-small-0.out"));
        io = new Kattio(new FileInputStream("round3/B-large-0.in"), new FileOutputStream("round3/B-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            System.err.println(i);
            new B().solve(io);
        }
        io.close();
    }

    int myPower, towerPower;
    int health[], gold[];

    private void solve(Kattio io) {
        myPower = io.getInt();
        towerPower = io.getInt();
        int n = io.getInt();
        health = new int[n];
        gold = new int[n];
        for (int i = 0; i < n; i++) {
            health[i] = io.getInt();
            gold[i] = io.getInt();
        }
        memo = new int[n][201*n+10];
        io.println(go(0, 1));
    }

    int memo[][];

    private int go(int monster, int savedTurns) {
        if (monster == health.length) return 0;
        int orgSavedTurns = savedTurns;
        if (memo[monster][savedTurns] > 0) return memo[monster][savedTurns] - 1;
        // skip it
        int towerShots = (health[monster] + towerPower - 1) / towerPower;
        int best = go(monster + 1, savedTurns + towerShots);

        int h = health[monster] % towerPower;
        if (h == 0) h = towerPower;
        int shotsReq = (h + myPower - 1) / myPower;
        savedTurns += towerShots - 1;
        if (shotsReq <= savedTurns) {
            best = Math.max(best, gold[monster] + go(monster + 1, savedTurns - shotsReq));
        }
        memo[monster][orgSavedTurns] = best + 1;
        return best;
    }
}
