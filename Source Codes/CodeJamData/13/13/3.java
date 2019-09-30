import java.util.*;

public class Luck1 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int numCases = in.nextInt();
    int numRows = in.nextInt();
    int setSize = in.nextInt(); // N
    int setLimit = in.nextInt(); // M
    int numProducts = in.nextInt(); // K
    long[] products = new long[numProducts];
    StringBuilder output = new StringBuilder();
    for (int caseNum = 1; caseNum <= numCases; ++caseNum) {
      output.append(String.format("Case #%d:\n", caseNum));
      for (int curRow = 0; curRow < numRows; ++curRow) {
        for (int i = 0; i < numProducts; ++i)
          products[i] = in.nextLong();
        
        int[] best = new int[setSize];
        Arrays.fill(best, 2);
        double bestProb = 0.0;
        
        for (int e1 = 2; e1 <= setLimit; ++e1) {
          for (int e2 = 2; e2 <= setLimit; ++e2) {
            for (int e3 = 2; e3 <= setLimit; ++e3) {
              // suppose our set is {e1, e2, e3}
              int[] tempSet = new int[] {e1, e2, e3};
              // determine likelihood of each product.
              double checkProb = 1.0;
              for (int pCheck = 0; pCheck < products.length; ++pCheck) {
                int counter = 0;
                for (int bitMask = 0; bitMask < (1 << tempSet.length); ++bitMask) {
                  int checkProduct = 1;
                  for (int bit = 1, idx = 0; bit <= bitMask; bit <<= 1, ++idx) {
                    if ( (bit & bitMask) != 0) {
                      checkProduct *= tempSet[idx];
                    }
                  }
                  if (checkProduct == products[pCheck]) {
                    ++counter;
                  }
                }
                checkProb *= (counter / 8.0);
              }
              //System.out.printf("Chance for set %s is %.6f\n", Arrays.toString(tempSet), checkProb);
              if (checkProb > bestProb) {
                //System.out.printf("%s is a better set!\n", Arrays.toString(tempSet));
                best = tempSet;
                bestProb = checkProb;
              }
            }
          }
        }
        output.append(best[0]);
        output.append(best[1]);
        output.append(best[2]);
        output.append('\n');
      }
    }
    System.out.print(output);
  }
}