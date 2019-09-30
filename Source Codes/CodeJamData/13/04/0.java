package exo4;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jean
 */
public class Treasure {

    public static void main(String[] args) {


        String base = "/home/jean/gcj2013/treasure/";
        String input = base + "b1.in";
        String output = base + "b1.out";

        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);

            int n = sc.nextInt();
            sc.nextLine();
            for (int c = 0; c < n; c++) {
                System.out.println("Test case " + (c + 1) + "...");
                pw.print("Case #" + (c + 1) + ": ");
                test(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Treasure.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static class Found extends Exception {
    }

    private static void test(Scanner sc, PrintWriter pw) {
        // reading input
        int K = sc.nextInt();
        int N = sc.nextInt();

        int[] cles = new int[201];
        //Reading starting keys
        for (int k = 0; k < K; k++) {
            cles[sc.nextInt()]++;
        }

        int[] chestTypes = new int[N];
        int[][] map = new int[N][];
        //Reading the map
        for (int n = 0; n < N; n++) {
            int Ti = sc.nextInt();
            int Ki = sc.nextInt();
            chestTypes[n] = Ti;
            map[n] = new int[Ki];
            // keys for this chest
            for (int k = 0; k < Ki; k++) {
                map[n][k] = sc.nextInt();
            }
        }

        //First, some stats.
        for (int i = 0; i < cles.length; i++) {
            int n = 0;
            int m = 0;
            for (int j = 0; j < chestTypes.length; j++) {
                if (chestTypes[j] == i) {
                    n++;
                }
                for (int p = 0; p < map[j].length; p++) {
                    if (map[j][p] == i) {
                        m++;
                    }
                }
            }

            m += cles[i];

//            if(n!=0) {
//                System.out.println("Chest needing key " + i + " : " + n);
//                System.out.println("Available keys " + i + " : " + m);
//            }
            if (n > m) {
                //We'll never find that many keys: impossible
                System.out.println("Not enough keys");
                pw.print("IMPOSSIBLE");
                return;
            }
        }


        //Now, let's explore the graph.
        //We'll store the moves done so far in arrays, in order to backtrack

        //List of the opened chests, from the start
        int[] chestsOpened = new int[N];
        boolean[] isOpened = new boolean[N];
        for (int i = 0; i < N; i++) {
            isOpened[i] = false;
        }

        try {
            solve(pw, cles, chestTypes, map, chestsOpened, isOpened, N, 0);
        } catch (Found ex) {
        }

    }
//    static int c = 0;

    private static void solve(PrintWriter pw, int[] cles, int[] chestTypes, int[][] map,
            int[] chestsOpened, boolean[] isOpened, int N, int s) throws Found {
//        c++;
//        if (c % 10000 == 0) {
//            System.out.println(c + " : " + s + " : ");
//            for (int i = 0; i < s; i++) {
//                System.out.print(chestsOpened[i] + " ");
//            }
//        }

//        System.out.print("Keys : ");
//        for (int i = 0; i < cles.length; i++) {
//            if (cles[i] != 0) {
//                for (int k = 0; k < cles[i]; k++) {
//                    System.out.print(i + " ");
//                }
//            }
//        }
//        System.out.println("");

        //If we opened all the chests, it's a win !
        if (N == s) {
            //We print the solution
            for (int i = 0; i < N; i++) {
                pw.print((chestsOpened[i] + 1) + " ");
            }
            throw new Found();
        }

        //To prune the research tree, we check that the situation isn't already hopeless.
        if (!accessCheck(N, cles, chestTypes, map, isOpened)) {
            //System.out.println("Backtracking2");
            // If s is 0, it means the problem is impossible
            if (s == 0) {
                pw.print("IMPOSSIBLE");
                return;
            }
            //Else we backtrack
            //We regain one key
            int co = chestsOpened[s - 1];
            cles[chestTypes[co]]++;
            //And lose some (or not)
            for (int k = 0; k < map[co].length; k++) {
                cles[map[co][k]]--;
            }
            isOpened[co] = false;
            return;
        }

        //Find the first chest that can be opened
        for (int i = 0; i < N; i++) {
            if (cles[chestTypes[i]] > 0 && !isOpened[i]) {
                //We open it
                //We lose one key
                cles[chestTypes[i]]--;
                //And find some (or not)
                for (int k = 0; k < map[i].length; k++) {
                    cles[map[i][k]]++;
                }
                //We store the move we just did
                chestsOpened[s] = i;
                isOpened[i] = true;
                //And we solve from there
                //System.out.println("Exploring chest " + i);
                solve(pw, cles, chestTypes, map, chestsOpened, isOpened, N, s + 1);
            }
        }
        // If we arrive here, no chest could be opened, we backtrack.
        // If s is 0, it means the problem is impossible
        if (s == 0) {
            pw.print("IMPOSSIBLE");
            return;
        }
        //System.out.println("Backtracking");
        // Else, we undo the previous move
        //We regain one key
        int co = chestsOpened[s - 1];
        cles[chestTypes[co]]++;
        //And lose some (or not)
        for (int k = 0; k < map[co].length; k++) {
            cles[map[co][k]]--;
        }
        isOpened[co] = false;
    }

    private static boolean accessCheck(int N, int[] cles, int[] chestTypes, int[][] map, boolean[] isOpened) {
        List<Integer> keysl = new ArrayList<Integer>(50);
        boolean keysv[] = new boolean[201];
        boolean chestv[] = new boolean[N];

        // At first, no keys visited
        for (int i = 0; i < keysv.length; i++) {
            keysv[i] = false;
        }

        // At first, no chests visited, unless the chest is already opened
        for (int i = 0; i < chestv.length; i++) {
            chestv[i] = isOpened[i];
        }

        // We visit keys in hand
        for (int k = 0; k < cles.length; k++) {
            if (cles[k] > 0) {
                keysl.add(k);
                keysv[k] = true;
            }
        }

        while (!keysl.isEmpty()) {
            int k = keysl.remove(0);
            //For every key in the queue, we visit the matching chests (not already opened)
            for (int i = 0; i < chestv.length; i++) {
                if (!chestv[i] && chestTypes[i] == k) {
                    //Add all the keys in the queue
                    for (int l = 0; l < map[i].length; l++) {
                        int kl = map[i][l];
                        if (!keysv[kl]) {
                            keysl.add(kl);
                            keysv[kl] = true;
                        }
                    }
                    //Mark the chest as visited
                    chestv[i] = true;
                }
            }

        }

        //We return false if one chest wasn't visited
        for (int i = 0; i < chestv.length; i++) {
            if (!chestv[i]) {
                //System.out.println("Chest " + i + " not accessible.");
                return false;
            }
        }

        return true;
    }
}
