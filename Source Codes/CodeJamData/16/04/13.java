// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.math.*;
import java.util.*;

public class D_Fractiles {
  // --------------------------------------------------------------------------------
  private static final String FILENAME="data/qualification/D-large";
  private static final boolean STANDARD_OUTPUT=false;
  private static BufferedReader in=null;
  private static PrintStream out=null;
  public static void main(String[] args) throws Throwable {
    try (BufferedReader reader=in=new BufferedReader(new FileReader(FILENAME+".in"))) {
      try (PrintStream writer=out=!STANDARD_OUTPUT?new PrintStream(FILENAME+".out"):System.out) {
        process();
      }
    }
  }
  // --------------------------------------------------------------------------------
  private static void process() throws Throwable {
    for (int caseNumber=1,T=Integer.parseInt(in.readLine()); caseNumber<=T; caseNumber++) {
      StringTokenizer tokenizer=new StringTokenizer(in.readLine());
      K=Integer.parseInt(tokenizer.nextToken());
      C=Integer.parseInt(tokenizer.nextToken());
      S=Integer.parseInt(tokenizer.nextToken());
      positions=new ArrayList<>();
      visited=new HashSet<>();
      f(BigInteger.ZERO,0);
      out.print("Case #"+caseNumber+":");
      if (positions.size()<=S) {
        for (BigInteger position:positions) {
          out.print(" "+position.add(BigInteger.ONE));
        }
        out.println();
      }
      else {
        out.println(" IMPOSSIBLE");
      }
    }
  }
  static int K,C,S;
  static List<BigInteger> positions;
  static Set<Integer> visited;
  static void f(BigInteger start, int c) {
    if (c==C||visited.size()==K) {
      positions.add(start);
    }
    else {
      BigInteger childSize=BigInteger.valueOf(K).pow(C-c-1);
      for (int i=0; i<K; i++) {
        if (!visited.contains(i)) {
          visited.add(i);
          f(start.add(childSize.multiply(BigInteger.valueOf(i))),c+1);
          if (c>0) break;
        }
      }
    }
  }
}
