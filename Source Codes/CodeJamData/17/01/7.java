// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class A_OversizedPancakeFlipper { // small: ?, large: ?
  private static final String FILENAME="A-large";
  private static final boolean STANDARD_OUTPUT=false;
  public static void main(String[] args) throws Throwable {
    try (BufferedReader in=new BufferedReader(new FileReader(FILENAME+".in"))) {
      try (PrintStream out=!STANDARD_OUTPUT?new PrintStream(FILENAME+".out"):System.out) {
        for (int t=1,T=Integer.parseInt(in.readLine()); t<=T; t++) {
          StringTokenizer tokenizer=new StringTokenizer(in.readLine());
          char[] S=tokenizer.nextToken().toCharArray();
          int K=Integer.parseInt(tokenizer.nextToken());
          BitSet bitSet=new BitSet(S.length);
          for (int i=0; i<S.length; i++) {
            if (S[i]=='-') bitSet.set(i);
          }
          int c=0;
          for (int i=0; i<=S.length-K; i++) {
            if (bitSet.get(i)) {
              c++;
              bitSet.flip(i,i+K);
            }
          }
          String solution=bitSet.cardinality()>0?"IMPOSSIBLE":""+c;
          out.println("Case #"+t+": "+solution);
        }
      }
    }
  }
}
