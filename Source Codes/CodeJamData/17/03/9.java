// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class C_BathroomStalls { // small1: OK, small2: OK, large: ?
  private static final String FILENAME="C-large";
  private static final boolean STANDARD_OUTPUT=false;
  public static void main(String[] args) throws Throwable {
    try (BufferedReader in=new BufferedReader(new FileReader(FILENAME+".in"))) {
      try (PrintStream out=!STANDARD_OUTPUT?new PrintStream(FILENAME+".out"):System.out) {
        for (int t=1,T=Integer.parseInt(in.readLine()); t<=T; t++) {
          StringTokenizer tokenizer=new StringTokenizer(in.readLine());
          long N=Long.parseLong(tokenizer.nextToken());
          long K=Long.parseLong(tokenizer.nextToken());
          long solution[]=solve(N,K);
          out.println("Case #"+t+": "+solution[0]+" "+solution[1]);
        }
      }
    }
  }
  static long[] solve(long N, long K) {
    long n=N,k=K,S[]=new long[2],T[]=new long[2];
    while (true) {
      S[1]=(n-1)>>>1;
      S[0]=n-1-S[1];
      T[1]=(k-1)>>>1;
      T[0]=k-1-T[1];
      if (k==1) return S;
      n=S[(int)(k&1)];
      k=T[(int)(k&1)];
    }
  }
  static int[] solveSlow(int N, int K) {
    boolean stalls[]=new boolean[N+2];
    stalls[0]=stalls[N+1]=true;
    for (int k=0; k<K; k++) {
      int best[]=null;
      for (int i=1; i<=N; i++) {
        if (stalls[i]) continue;
        int lS=0,rS=0;
        for (int j=i-1; j>=1&&!stalls[j]; j--,lS++) {
        }
        for (int j=i+1; j<=N&&!stalls[j]; j++,rS++) {
        }
        int option[]={Math.max(lS,rS),Math.min(lS,rS),i};
        if (best==null||option[1]>best[1]||(option[1]==best[1]&&(option[0]>best[0]||(option[0]==best[0]&&option[2]<best[2])))) best=option;
      }
      if (best==null||stalls[best[2]]) throw new IllegalStateException();
      stalls[best[2]]=true;
      if (k==K-1) return best;
    }
    return null;
  }
}
