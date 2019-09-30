import java.util.*;

public class Main {
    static int modP = 1000000007;
    static long inf = 1 << 61;
    static int[] x4 = {-1, 0, 0, 1};
    static int[] y4 = {0, -1, 1, 0};
    static int[] x8 = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] y8 = {0, -1, -1, -1, 0, 1, 1, 1};

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int l = in.nextInt();
        int[] W = new int[l];
        for(int i = 0; i < l; i++) {
            W[i] = in.nextInt();
        }

        int[] stack = new int[l+1];
        stack[0] = W[0];
        int stackNum = 1;

        for(int i = 1; i < l; i++) {
            int w = W[i];
            int minStackWeightDiff = Integer.MAX_VALUE;
            int minStackWeightDiffIndex = -1;
            for(int j = 0; j < stackNum; j++) {
                int jw = stack[j];
                int weightDiff = Math.abs(jw-w);
                if(w <= jw && minStackWeightDiff >= weightDiff) {
                    minStackWeightDiff = weightDiff;
                    minStackWeightDiffIndex = j;
                }
            }

            if(minStackWeightDiffIndex != -1) {
                stack[minStackWeightDiffIndex] = w;
            }else{
                stack[stackNum] = w;
                stackNum++;
            }
        }

        System.out.println(stackNum);
    }

    static public void printArray2D(char[][] map) {
        for(int i = 0; i < map.length; i++) {
            for(int j = 0; j < map[i].length; j++) {
                System.out.format("%c\t", map[i][j]);
            }
            System.out.print("\n");
        }
    }

    static public void printArray2D(int[][] map) {
        for(int i = 0; i < map.length; i++) {
            for(int j = 0; j < map[i].length; j++) {
                System.out.format("%d\t", map[i][j]);
            }
            System.out.print("\n");
        }
    }
}