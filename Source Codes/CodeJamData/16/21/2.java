package round1b;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class A {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round1b/A-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("round1b/A-small-attempt0.in"), new FileOutputStream("round1b/A-small-0.out"));
        io = new Kattio(new FileInputStream("round1b/A-large.in"), new FileOutputStream("round1b/A-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new A().solve(io);
        }
        io.close();
    }



    private void solve(Kattio io) {
        String[] digits = new String[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
        String word = io.getWord();
        int[] cnt = new int[126];
        for (char c : word.toCharArray()) {
            cnt[c]++;
        }

        int[] ans = new int[10];

        while (true) {
            int dig;
            if (cnt['Z'] > 0) {
                dig = 0;
            } else if (cnt['W'] > 0) {
                dig = 2;
            } else if (cnt['X'] > 0) {
                dig = 6;
            } else if (cnt['G'] > 0) {
                dig = 8;
            } else if (cnt['H'] > 0) {
                dig = 3;
            } else if (cnt['R'] > 0) {
                dig = 4;
            } else if (cnt['F'] > 0) {
                dig = 5;
            } else if (cnt['I'] > 0) {
                dig = 9;
            } else if (cnt['V'] > 0) {
                dig = 7;
            } else if (cnt['O'] > 0) {
                dig = 1;
            } else {
                for (int i = 0; i < 126; i++) {
                    if (cnt[i] > 0) {
                        throw new RuntimeException();
                    }
                }
                break;
            }
            for (char c : digits[dig].toCharArray()) {
                cnt[c]--;
                if (cnt[c] < 0) throw new RuntimeException();
            }
            ans[dig]++;
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < ans[i]; j++) {
                io.print(i);
            }
        }
        io.println();
    }
}
