package round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class D {
    int turns, scores, opened;
    int[] c, s, t;
    List<Integer> current;
    int n, m;


    private void updateWithIndex(int index) {
        turns += t[index];
        scores += s[index];
        if (c[index] != 0) {
            // max plus
            int maxPlus = Math.min(n + m - opened - 1, c[index]);
            for (int j = opened + 1; j <= opened + maxPlus; j++) {
                current.add(j);
            }

            opened += maxPlus;
        }

        List<Integer> newList = new ArrayList<Integer>();
        for (int i = 0; i < current.size(); i++) {
            if (current.get(i) != index) {
                newList.add(current.get(i));
            }
        }
        current = newList;
    }

    private int getMaximumScoreNot0C() {
        int maxScoreIndex = -1;
        for (int index : current) {
            if (c[index] != 0) {
                if (maxScoreIndex == -1 || s[maxScoreIndex] < s[index]) {
                    maxScoreIndex = index;
                }
            }
        }
        return maxScoreIndex;
    }

    private int getMaximumScore() {
        int maxScoreIndex = -1;
        for (int index : current) {
            if (maxScoreIndex == -1 || s[maxScoreIndex] < s[index]) {
                maxScoreIndex = index;
            }

        }
        return maxScoreIndex;
    }


    public void run(Scanner input, PrintWriter output) {
        n = input.nextInt();

        int[] c1 = new int[n];
        int[] s1 = new int[n];
        int[] t1 = new int[n];

        for (int i = 0; i < n; i++) {
            c1[i] = input.nextInt();
            s1[i] = input.nextInt();
            t1[i] = input.nextInt();
        }

        m = input.nextInt();
        c = new int[n + m];
        s = new int[n + m];
        t = new int[n + m];

        for (int i = 0; i < n; i++) {
            c[i] = c1[i];
            s[i] = s1[i];
            t[i] = t1[i];
        }
        for (int i = n; i < n + m; i++) {
            c[i] = input.nextInt();
            s[i] = input.nextInt();
            t[i] = input.nextInt();
        }

        // end input

        // пока есть хоть одно t !=0 можно его разыгрывать хуже не будет
        // дойти до такого то места, с t = такому то (если есть не нулевые сразу юзаем), с таким то колвом купонов на открываение 1,

        // израсходовали где t != 0
        // есть очки и с[i]
        // go to nth
        int ans = 0;

        for (int i = n - 1; i < n + m; i++) {
            // i - the last
            current = new ArrayList<Integer>();
            for (int j = 0; j < n; j++) {
                current.add(j);
            }

            turns = 1;
            scores = 0;
            opened = n - 1; // last opened

            while (turns > 0 && current.size() > 0) {
                turns--;
                // optimize with t
                int tNot0 = -1;
                for (int index : current) {
                    if (t[index] != 0) {
                        tNot0 = index;
                        break;
                    }
                }
                if (tNot0 != -1) {
                    updateWithIndex(tNot0);
                } else {
                    // all t - zero
                    // open with max c. if i-opened == 1 find c == 1 or 2 but with max score, else find c == 2 .
                    // easy. c[i] = 1

                    if (opened == i) {
                        updateWithIndex(getMaximumScore());
                    } else {
                        if (getMaximumScoreNot0C() == -1) {
                            updateWithIndex(getMaximumScore());
                        } else {
                            updateWithIndex(getMaximumScoreNot0C());
                        }
                    }
                }
            }

            ans = Math.max(ans, scores);
        }

        output.println(ans);
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner input = new Scanner(new File("input.txt"));
        PrintWriter output = new PrintWriter(new File("output.txt"));

        D sol = new D();

        int t = input.nextInt();
        for (int i = 0; i < t; i++) {
            output.print("Case #" + (i + 1) + ": ");
            sol.run(input, output);
        }

        input.close();
        output.close();
    }
}
