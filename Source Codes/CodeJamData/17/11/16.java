import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by jzj on 14/04/2017.
 */
public class ProblemA {

    private static int[] minI;
    private static int height;
    private static int width;
    private static int[] maxI;
    private static int[] minJ;
    private static int[] maxJ;
    private static char[][] cake;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCount = in.nextInt();
        for (int testNo = 1; testNo <= testCount; testNo++) {
            solve(testNo, in);
        }
    }

    static char[][][][] state;

    private static void solve(int testNo, Scanner in) {
        height = in.nextInt();
        width = in.nextInt();
        minI = new int[256];
        maxI = new int[256];
        minJ = new int[256];
        maxJ = new int[256];
        cake = new char[height][];
        for (int i = 0; i < height; i++) {
            cake[i] = in.next().toCharArray();
        }
        Arrays.fill(minI, Integer.MAX_VALUE);
        Arrays.fill(minJ, Integer.MAX_VALUE);
        Arrays.fill(maxI, Integer.MIN_VALUE);
        Arrays.fill(maxJ, Integer.MIN_VALUE);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                char c = cake[i][j];
                if (c != '?') {
                    minI[c] = Math.min(minI[c], i);
                    minJ[c] = Math.min(minJ[c], j);
                    maxI[c] = Math.max(maxI[c], i);
                    maxJ[c] = Math.max(maxJ[c], j);
                }
            }
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            if (minI[c] != Integer.MAX_VALUE) {
                for (int i = minI[c]; i <= maxI[c]; i++) {
                    for (int j = minJ[c]; j <= maxJ[c]; j++) {
                        if (cake[i][j] != c && cake[i][j] != '?') {
                            throw new RuntimeException();
                        }
                        cake[i][j] = c;
                    }
                }
            }
        }
        print(0, height, 0  , width);
        System.out.println("Case #" + testNo + ":");
        for (char[] chars : cake) {
            System.out.println(chars);
        }
    }

    private static void print(int fromI, int toI, int fromJ, int toJ) {
        int in = 0;
        char c0 = '?';
        for (char c = 'A'; c <= 'Z'; c++) {
            if (minI[c] != Integer.MAX_VALUE) {
                if ((maxI[c] >= fromI && minI[c] < toI) && (maxJ[c] >= fromJ && minJ[c] < toJ)) {
                    in++;
                    c0 = c;
                }
            }
        }
        if (in == 0) {
            throw new RuntimeException();
        }
        if (in == 1) {
            for (int i = fromI; i < toI; i++) {
                for (int j = fromJ; j < toJ; j++) {
                    cake[i][j] = c0;
                }
            }
            return;
        }
        int inL = 0;
        int inR = 0;
        tag2:
        for (int divI = fromI + 1; divI < toI; divI++) {
            inL = 0;
            inR = 0;
            for (char c = 'A'; c <= 'Z'; c++) {
                if (minI[c] != Integer.MAX_VALUE) {
                    int ct = 0;
                    if ((maxI[c] >= fromI && minI[c] < divI) && (maxJ[c] >= fromJ && minJ[c] < toJ)) {
                        inL++;
                        ct++;
                    }
                    if ((maxI[c] >= divI && minI[c] < toI) && (maxJ[c] >= fromJ && minJ[c] < toJ)) {
                        inR++;
                        ct++;
                    }
                    if (ct == 2) {
                        continue tag2;
                    }

                }
            }
            if (inL == 0 || inR == 0) {
                continue;
            }
            print(fromI, divI, fromJ, toJ);
            print(divI, toI, fromJ, toJ);
            return;
        }
        tag3:
        for (int divJ = fromJ + 1; divJ < toJ; divJ++) {
            inL = 0;
            inR = 0;
            for (char c = 'A'; c <= 'Z'; c++) {
                if (minI[c] != Integer.MAX_VALUE) {
                    int ct = 0;
                    if ((maxI[c] >= fromI && minI[c] < toI) && (maxJ[c] >= fromJ && minJ[c] < divJ)) {
                        inL++;
                        ct++;
                    }
                    if ((maxI[c] >= fromI && minI[c] < toI) && (maxJ[c] >= divJ && minJ[c] < toJ)) {
                        inR++;
                        ct++;
                    }
                    if (ct == 2) {
                        continue tag3;
                    }
                }
            }
            if (inL == 0 || inR == 0) {
                continue;
            }
            print(fromI, toI, fromJ, divJ);
            print(fromI, toI, divJ, toJ);
            return;
        }
        throw new RuntimeException();
    }

}
