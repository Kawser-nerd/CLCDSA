package round1c;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.HashMap;

public class B {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round1c/B-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("round1c/B-small-attempt0.in"), new FileOutputStream("round1c/B-small-0.out"));
        io = new Kattio(new FileInputStream("round1c/B-large.in"), new FileOutputStream("round1c/B-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new B().solve(io);
        }
        io.close();
    }

    private String keyboard, target;

    private void solve(Kattio io) {
        int K = io.getInt(), L = io.getInt(), S = io.getInt();
        keyboard = io.getWord();
        target = io.getWord();
        int next = -1;
        for (int i = 0; i < target.length(); i++) {
            if (target.startsWith(target.substring(i + 1))) {
                next = i+1;
                break;
            }
        }
        int max = 0, pos = 0;
        while (pos + target.length() <= S) {
            max++;
            pos += next;
        }
        for (char c : target.toCharArray()) {
            if (!keyboard.contains("" + c)) {
                max = 0;
            }
        }
        if (max == 0) {
            io.println(max);
            return;
        }

        findPosCache = new HashMap<>();
        memoDone = new boolean[S+1][target.length() + 1];
        memo = new double[S+1][target.length() + 1];
        io.println(String.format("%.8f", max - go(S, 0)));
        io.flush();
    }

    private HashMap<String, Integer> findPosCache;

    private int findPos(String s) {
        if (findPosCache.containsKey(s)) return findPosCache.get(s);
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (target.startsWith(s.substring(i + 1))) {
                res = s.length() - (i + 1);
                break;
            }
        }
        findPosCache.put(s, res);
        return res;
    }

    private boolean memoDone[][];
    private double memo[][];

    private double go(final int lettersLeft, final int pos) {
        double e = 0.0;
        int pos2 = pos;
        if (pos2 == target.length()) {
            e = 1.0;
            pos2 = findPos(target);
        }
        if (lettersLeft == 0) {
            return e;
        }

        if (memoDone[lettersLeft][pos]) {
            return memo[lettersLeft][pos];
        }

        double sum = 0.0;
        for (int i = 0; i < keyboard.length(); i++) {
            char c = keyboard.charAt(i);
            int newPos = pos2;
            if (target.charAt(pos2) == c) {
                newPos++;
            } else {
                newPos = findPos(target.substring(0, newPos) + c);
            }
            sum += e + go(lettersLeft - 1, newPos);
        }

        double exp = sum / keyboard.length();

        memoDone[lettersLeft][pos] = true;
        memo[lettersLeft][pos] = exp;

        return exp;
    }
}
