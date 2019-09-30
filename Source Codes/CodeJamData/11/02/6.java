import java.util.Arrays;
import java.util.Scanner;


public class Magicka {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int nbTests = s.nextInt();
        boolean[] oppAct = new boolean[8];
        boolean[] present = new boolean[8];
        for (int numTest = 1 ; numTest <= nbTests ; numTest++) {
            s.nextLine();
            char[][] comb = new char[8][8];
            int nbComb = s.nextInt();
            for (int i = 0 ; i < nbComb ; i++) {
                String sComb = s.next();
                comb[intValue(sComb.charAt(0))][intValue(sComb.charAt(1))] = sComb.charAt(2);
                comb[intValue(sComb.charAt(1))][intValue(sComb.charAt(0))] = sComb.charAt(2);
            }
            boolean[][] opp = new boolean[8][8];
            int nbOpp = s.nextInt();
            for (int i = 0 ; i < nbOpp ; i++) {
                String sComb = s.next();
                opp[intValue(sComb.charAt(0))][intValue(sComb.charAt(1))] = true;
                opp[intValue(sComb.charAt(1))][intValue(sComb.charAt(0))] = true;
            }
            Arrays.fill(oppAct, false);
            Arrays.fill(present, false);
            int nbElems = s.nextInt();
            char[] stack = new char[nbElems];
            String elems = s.next();
            char next;
            int nextInt;
            int last = -1;
            int elemsInStack = 0;
            for (int elemAct = 0 ; elemAct < nbElems ; elemAct++) {
                next = elems.charAt(elemAct);
                nextInt = intValue(next);
                if (last != -1 && comb[nextInt][last] != 0) {
                    stack[elemsInStack-1] = comb[nextInt][last];
                    last = -1;
                } else {
                    if (last != -1 && !present[last]) {
                        present[last] = true;
                        for (int i = 0 ; i < 8 ; i++) {
                            if (opp[last][i]) {
                                oppAct[i] = true;
                            }
                        }
                    }
                    if (oppAct[nextInt]) {
                        Arrays.fill(oppAct, false);
                        Arrays.fill(present, false);
                        last = -1;
                        elemsInStack = 0;
                    } else {
                        last = nextInt;
                        stack[elemsInStack++] = next;
                    }
                }
            }
            System.out.print("Case #");
            System.out.print(numTest);
            System.out.print(": [");
            if (elemsInStack != 0) {
                System.out.print(stack[0]);
            }
            for (int i = 1 ; i < elemsInStack ; i++) {
                System.out.print(", ");
                System.out.print(stack[i]);
            }
            System.out.println(']');
        }
    }
    
    
    private static int intValue(char c) {
        switch (c) {
            case 'Q': return 0;
            case 'W': return 1;
            case 'E': return 2;
            case 'R': return 3;
            case 'A': return 4;
            case 'S': return 5;
            case 'D': return 6;
            case 'F': return 7;
        }
        throw new RuntimeException();
    }
}
