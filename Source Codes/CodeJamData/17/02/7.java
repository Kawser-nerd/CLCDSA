// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class B_TidyNumbers { // small: OK, large: ?
  private static final String FILENAME="B-large";
  private static final boolean STANDARD_OUTPUT=false;
  public static void main(String[] args) throws Throwable {
    try (BufferedReader in=new BufferedReader(new FileReader(FILENAME+".in"))) {
      try (PrintStream out=!STANDARD_OUTPUT?new PrintStream(FILENAME+".out"):System.out) {
        for (int t=1,T=Integer.parseInt(in.readLine()); t<=T; t++) {
          char[] N=in.readLine().toCharArray();
          int i=1,k=0;
          for (i=1; i<N.length&&N[i]>=N[i-1]; i++) {
          }
          if (i<N.length) {
            for (k=i-1; k>=0&&N[k]==N[i-1]; k--) {
            }
            N[++k]--;
            Arrays.fill(N,k+1,N.length,'9');
            k=k==0&&N[0]=='0'?1:0;
          }
          out.println("Case #"+t+": "+new String(N,k,N.length-k));
        }
      }
    }
  }
}
