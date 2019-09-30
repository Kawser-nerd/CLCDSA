// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class B_RevengeOfThePancakes {
  // --------------------------------------------------------------------------------
  private static final String FILENAME="data/qualification/B-large";
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
      String stack=in.readLine();
      int answer=solveFast(stack);
      out.println("Case #"+caseNumber+": "+answer);
    }
  }
  private static int solveFast(String stack) {
    int c=0;
    for (int i=1; i<stack.length(); i++) {
      if (stack.charAt(i)!=stack.charAt(i-1)) c++;
    }
    if (stack.charAt(stack.length()-1)=='-') c++;
    return c;
  }
  @SuppressWarnings("unused")
  private static int solveSlow(String stack) {
    Map<String,Integer> scores=new HashMap<>();
    Deque<String> deque=new ArrayDeque<>();
    scores.put(stack,0);
    deque.addLast(stack);
    while (!deque.isEmpty()) {
      String string=deque.removeFirst();
      if (string.indexOf('-')==-1) return scores.get(string);
      for (int i=1; i<=string.length(); i++) {
        String nextString=reverse(string.substring(0,i))+string.substring(i);
        if (!scores.containsKey(nextString)) {
          scores.put(nextString,scores.get(string)+1);
          deque.addLast(nextString);
          if (nextString.indexOf('-')==-1) return scores.get(nextString);
        }
      }
    }
    return Integer.MAX_VALUE;
  }
  private static String reverse(String string) {
    StringBuilder stringBuilder=new StringBuilder(string.length());
    for (int i=string.length()-1; i>=0; i--) {
      stringBuilder.append(string.charAt(i)=='+'?'-':'+');
    }
    return stringBuilder.toString();
  }
}
