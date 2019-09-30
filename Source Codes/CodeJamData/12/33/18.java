// Author: Alejandro Sotelo Arevalo
package round1c;

import java.io.*;
import java.util.*;

public class C_BoxFactory {
  // --------------------------------------------------------------------------------
  private static String ID="C";
  private static String NAME="large";
  private static boolean STANDARD_OUTPUT=false;
  // --------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    BufferedReader reader=new BufferedReader(new FileReader(new File("data/"+ID+"-"+NAME+".in")));
    if (!STANDARD_OUTPUT) System.setOut(new PrintStream(new File("data/"+ID+"-"+NAME+".out")));
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      String w[]=reader.readLine().trim().split(" +");
      map.clear();
      A=read(reader.readLine().trim().split(" +"),Integer.parseInt(w[0]));
      B=read(reader.readLine().trim().split(" +"),Integer.parseInt(w[1]));
      // System.out.println(Arrays.deepToString(A));
      // System.out.println(Arrays.deepToString(B));
      System.out.println("Case #"+c+": "+dp(A.length-1,B.length-1,0,0));
    }
    if (!STANDARD_OUTPUT) System.out.close();
    reader.close();
  }
  private static long[][] A,B;
  private static Map<State,Long> map=new HashMap<State,Long>();
  private static long[][] read(String[] w, int N) {
    List<long[]> R=new ArrayList<long[]>();
    long[] last=null;
    for (int i=0,k=0; i<N; i++) {
      long quantity=Long.parseLong(w[k++]);
      long type=Long.parseLong(w[k++]);
      if (last==null||type!=last[1]) {
        R.add(last=new long[]{quantity,type});
      }
      else {
        last[0]+=quantity;
      }
    }
    return R.toArray(new long[0][]);
  }
  private static long dp(int i, int j, long lastI, long lastJ) { // Dynamic Programming
    if (i==-1||j==-1) return 0;
    State state=new State(i,j,lastI,lastJ);
    Long result=map.get(state);
    if (result!=null) return result;
    long best=0;
    if (A[i][1]!=B[j][1]) {
      best=Math.max(best,Math.max(dp(i-1,j,0,lastJ),dp(i,j-1,lastI,0)));
    }
    else if (A[i][0]-lastI==B[j][0]-lastJ) {
      long c=A[i][0]-lastI;
      best=Math.max(best,dp(i-1,j-1,0,0)+c);
    }
    else if (A[i][0]-lastI<B[j][0]-lastJ) {
      long c=A[i][0]-lastI;
      best=Math.max(best,dp(i-1,j,0,lastJ+c)+c);
    }
    else {
      long c=B[j][0]-lastJ;
      best=Math.max(best,dp(i,j-1,lastI+c,0)+c);
    }
    map.put(state,best);
    return best;
  }
  private static class State {
    int i,j;
    long lastI,lastJ;
    public State(int i, int j, long lastI, long lastJ) {
      this.i=i;
      this.j=j;
      this.lastI=lastI;
      this.lastJ=lastJ;
    }
    public boolean equals(Object object) {
      if (!(object instanceof State)) return false;
      State st1=this,st2=(State)object;
      return st1.i==st2.i&&st1.j==st2.j&&st1.lastI==st2.lastI&&st1.lastJ==st2.lastJ;
    }
    public int hashCode() {
      return (int)(((i^j)<<16)^(lastI^lastJ));
    }
  }
}
