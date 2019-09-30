package codejam.round1c_2012;

import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class MainC {

    static long[][] toyProductionSum;
    static long[][] boxProductionSum;
    static int boxCount, toyCount;
    static long[] boxProduction;
    static int[] boxType;
    static long[] toyProduction;
    static int[] toyType;
    static int waterheight;
    
    public static void main(String[] args) throws Exception {

        String f = "/home/floris/dev/java/Test/src/codejam/round1c_2012/C-large.in";
        Scanner sc = new Scanner(new File(f));
        System.setOut(new PrintStream(new File(f+".out")));
        int T = sc.nextInt();
        for (int i=1; T-- > 0; i++) {
            boxCount = sc.nextInt();
            toyCount = sc.nextInt();
            boxProduction = new long[boxCount];
            boxType = new int[boxCount];
            for (int r = 0; r < boxCount; r++) {
                boxProduction[r] = sc.nextLong();
                boxType[r] = sc.nextInt()-1;
            }
            toyProduction = new long[toyCount];
            toyType = new int[toyCount];
            for (int r = 0; r < toyCount; r++) {
                toyProduction[r] = sc.nextLong();
                toyType[r] = sc.nextInt()-1;
            }
            
            System.out.printf("Case #%d: %d%n", i, solve());
        }
    }

    private static long solve() {
        toyProductionSum = new long[100][toyCount];
        for (int t = 0; t < 100; t++) {
            long s = 0;
            for (int i = 0; i < toyCount; i++) {
                if (toyType[i]==t) s+=toyProduction[i];
                toyProductionSum[t][i]=s;
            }
        }
        boxProductionSum = new long[100][boxCount];
        for (int t = 0; t < 100; t++) {
            long s = 0;
            for (int i = 0; i < boxCount; i++) {
                if (boxType[i]==t) s+=boxProduction[i];
                boxProductionSum[t][i]=s;
            }
        }
        long[][] grid = new long[toyCount][boxCount];
        for (int r = 0; r < toyCount; r++) {
            for (int c = 0; c < boxCount; c++) {
                long best = Math.max(
                        Math.min(boxProductionSum[boxType[c]][c], toyProductionSum[boxType[c]][r]),
                        Math.min(boxProductionSum[toyType[r]][c], toyProductionSum[toyType[r]][r])
                        );
                for (int ri = 0; ri <= r; ri++) {
                    for (int ci = 0; ci <= c; ci++) {
                        long v = grid[ri][ci]+Math.max(
                            Math.min(boxProductionSum[boxType[c]][c]-boxProductionSum[boxType[c]][ci], toyProductionSum[boxType[c]][r]-toyProductionSum[boxType[c]][ri]),
                            Math.min(boxProductionSum[toyType[r]][c]-boxProductionSum[toyType[r]][ci], toyProductionSum[toyType[r]][r]-toyProductionSum[toyType[r]][ri])
                            );
                        if (v>best) best = v;
                    }
                }
                grid[r][c] = best;
            }
        }
//        System.err.println("---");
//        for (int r = 0; r < toyCount; r++) {
//            for (int c = 0; c < boxCount; c++) {
//                System.err.print(grid[r][c] + " ");
//            }
//            System.err.println("");
//        }
        return grid[toyCount-1][boxCount-1];
    }
    
}