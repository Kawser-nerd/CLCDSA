// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;

public class A_CountingSheep {
  // --------------------------------------------------------------------------------
  private static final String FILENAME="data/qualification/A-large";
  private static final boolean STANDARD_OUTPUT=false;
  private static BufferedReader in=null;
  private static PrintWriter out=null;
  public static void main(String[] args) throws Throwable {
    try (BufferedReader reader=in=new BufferedReader(new FileReader(FILENAME+".in"))) {
      try (PrintWriter writer=out=!STANDARD_OUTPUT?new PrintWriter(FILENAME+".out"):new PrintWriter(System.out)) {
        process();
      }
    }
  }
  // --------------------------------------------------------------------------------
  private static void process() throws Throwable {
    for (int caseNumber=1,T=Integer.parseInt(in.readLine()); caseNumber<=T; caseNumber++) {
      long N=Long.parseLong(in.readLine());
      long n=0L,m=0L;
      if (N>0) {
        boolean[] visited=new boolean[10];
        int visitedCount=0;
        loop: for (n=N; visitedCount<10; n+=N) {
          for (m=n; m>0; m/=10) {
            if (!visited[(int)(m%10)]) {
              visited[(int)(m%10)]=true;
              visitedCount++;
              if (visitedCount==10) break loop;
            }
          }
        }
      }
      out.println("Case #"+caseNumber+": "+(n==0L?"INSOMNIA":n));
    }
  }
}
