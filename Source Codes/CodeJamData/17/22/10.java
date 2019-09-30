

import java.io.*;
import java.util.*;

public class Stable {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    int N, R, O, Y, G, B, V;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        N = scan.nextInt();
        R = scan.nextInt();
        O = scan.nextInt();
        Y = scan.nextInt();
        G = scan.nextInt();
        B = scan.nextInt();
        V = scan.nextInt();
        if (doPair(O, B, "O", "B")) return;
        if (doPair(G, R, "G", "R")) return;
        if (doPair(V, Y, "V", "Y")) return;
        if ((O > 0 && B <= O) 
            || (G > 0 && R <= G)
            || (V > 0 && Y <= V)) {
            System.out.println("IMPOSSIBLE");
            return;
        }
        // treat BOBOBOBOB like a B, etc.
        B -= O;
        R -= G;
        Y -= V;
        if (R >= Y && Y >= B) {
            doIt(R, Y, B, G, V, O, "RYBGVO");
            return;
        }
        if (R >= B && B >= Y) {
            doIt(R, B, Y, G, O, V, "RBYGOV");
            return;
        }
        if (Y >= R && R >= B) {
            doIt(Y, R, B, V, G, O, "YRBVGO");
            return;
        }
        if (Y >= B && B >= R) {
            doIt(Y, B, R, V, O, G, "YBRVOG");
            return;
        }
        if (B >= R && R >= Y) {
            doIt(B, R, Y, O, G, V, "BRYOGV");
            return;
        }
        if (B >= Y && Y >= R) {
            doIt(B, Y, R, O, V, G, "BYROVG");
            return;
        }
        throw new AssertionError();
    }
    
    private void doIt(int max, int mid, int min, int maxComp, int midComp, int minComp, String string) {
        if (mid + min < max) {
            System.out.println("IMPOSSIBLE");
            return;
        }
        String maxString = string.substring(0,1);
        String midString = string.substring(1,2);
        String minString = string.substring(2,3);
        String maxCompString = string.substring(3,4);
        String midCompString = string.substring(4,5);
        String minCompString = string.substring(5,6);
        int minOnly = max - mid;
        int midAndMin = min - minOnly;
        int midOnly = mid - midAndMin;
        boolean sawMaxComp = false;
        boolean sawMidComp = false;
        boolean sawMinComp = false;
        for (int i = 0; i < minOnly; i++) {
            System.out.print(maxString);
            if (!sawMaxComp) {
                for (int j = 0; j < maxComp; j++) {
                    System.out.print(maxCompString + maxString);
                }
                sawMaxComp = true;
            }
            System.out.print(minString);
            if (!sawMinComp) {
                for (int j = 0; j < minComp; j++) {
                    System.out.print(minCompString + minString);
                }
                sawMinComp = true;
            }
        }
        for (int i = 0; i < midOnly; i++) {
            System.out.print(maxString);
            if (!sawMaxComp) {
                for (int j = 0; j < maxComp; j++) {
                    System.out.print(maxCompString + maxString);
                }
                sawMaxComp = true;
            }
            System.out.print(midString);
            if (!sawMidComp) {
                for (int j = 0; j < midComp; j++) {
                    System.out.print(midCompString + midString);
                }
                sawMidComp = true;
            }
        }
        for (int i = 0; i < midAndMin; i++) {
            System.out.print(maxString);
            if (!sawMaxComp) {
                for (int j = 0; j < maxComp; j++) {
                    System.out.print(maxCompString + maxString);
                }
                sawMaxComp = true;
            }
            System.out.print(midString);
            if (!sawMidComp) {
                for (int j = 0; j < midComp; j++) {
                    System.out.print(midCompString + midString);
                }
                sawMidComp = true;
            }
            System.out.print(minString);
            if (!sawMinComp) {
                for (int j = 0; j < minComp; j++) {
                    System.out.print(minCompString + minString);
                }
                sawMinComp = true;
            }
        }
        System.out.println();
    }

    private boolean doPair(int a, int b, String aString, String bString) {
        if (a + b < N) return false;
        if (a  != b) {
            System.out.println("IMPOSSIBLE");
            return true;
        }
        for (int i = 0; i < a; i++) {
            System.out.print(aString + bString);
        }
        System.out.println();
        return true;
    }

    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Stable().run();
    }

}
