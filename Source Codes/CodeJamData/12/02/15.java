// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class B_DancingWithTheGooglers {
  //--------------------------------------------------------------------------------
  private static String ID="B";
  private static String NAME="large";
  private static boolean STANDARD_OUTPUT=false;
  //--------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    BufferedReader reader=new BufferedReader(new FileReader(new File("data/"+ID+"-"+NAME+".in")));
    if (!STANDARD_OUTPUT) System.setOut(new PrintStream(new File("data/"+ID+"-"+NAME+".out")));
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      String w[]=reader.readLine().trim().split(" +");
      int N=Integer.parseInt(w[0]),S=Integer.parseInt(w[1]),p=Integer.parseInt(w[2]);
      int t[]=new int[N];
      for (int i=0; i<N; i++) t[i]=Integer.parseInt(w[3+i]);
      int result=dynamicProgrammingApproach2(N,S,p,t); // Time complexity: O(N*S), Space complexity: O(S)
      System.out.println("Case #"+c+": "+result);
    }
    if (!STANDARD_OUTPUT) System.out.close();
    reader.close();
  }
  private static int testCount=0;
  public static void test() {
    for (int k=0; k<=3; k++) {
      System.out.println("test k="+k);
      testCount=0;
      test(0,new int[k]);
    }
    System.out.println("random tests");
    testCount=0;
    Random random=new Random(0);
    for (int v=0,V=10000; v<V; v++) {
      int N=random.nextInt(6)+1,t[]=new int[N];
      for (int i=0; i<N; i++) t[i]=random.nextInt(31);
      for (int S=0; S<=N; S++) for (int p=0; p<=30; p++) test(N,S,p,t);
      System.out.println("testCount="+(++testCount)+"/"+V);
    }
  }
  private static void test(int k, int[] t) {
    if (k==t.length) {
      int N=t.length;
      for (int S=0; S<=N; S++) for (int p=0; p<=30; p++) test(N,S,p,t);
      System.out.println("testCount="+(++testCount)+"/"+java.math.BigInteger.valueOf(31).pow(N));
      return;
    }
    for (int option=0; option<=30; option++) {
      t[k]=option;
      test(k+1,t);
    }
  }
  private static void test(int N, int S, int p, int[] t) {
    int count=0;
    for (int i=0; i<N; i++) {
      if (t[i]>=2&&t[i]<=28) count++;
    }
    if (count<S) return;
    int result1=bruteForce(N,S,p,t);
    int result2=recursiveApproach1(N,S,p,t);
    int result3=recursiveApproach2(N,S,p,t);
    int result4=dynamicProgrammingApproach1(N,S,p,t);
    int result5=dynamicProgrammingApproach2(N,S,p,t);
    if (result2!=result1||result3!=result1||result4!=result1||result5!=result1) {
      System.out.println("ERROR:");
      System.out.println("N="+N);
      System.out.println("S="+N);
      System.out.println("p="+N);
      System.out.println("t="+Arrays.toString(t));
      System.out.println("result1="+result1);
      System.out.println("result2="+result2);
      System.out.println("result3="+result3);
      System.out.println("result4="+result4);
      System.out.println("result5="+result5);
      throw new IllegalStateException("Wrong result.");
    }
  }
  private static int bruteForce(int N, int S, int p, int[] t) {
    int result=0;
    for (int b=0,M=(1<<N); b<M; b++) if (Integer.bitCount(b)==S) {
      int count=0;
      for (int i=0; i<N; i++) {
        int best=-1;
        for (int c1=0; c1<=10; c1++) for (int c2=0; c2<=10; c2++) for (int c3=0; c3<=10; c3++) if (c1+c2+c3==t[i]) {
          int max=Math.max(c1,Math.max(c2,c3));
          int min=Math.min(c1,Math.min(c2,c3));
          if (((b>>>i)&1)==1) { // surprising
            if (max-min==2) best=Math.max(best,max);
          }
          else {
            if (max-min<=1) best=Math.max(best,max);
          }
        }
        if (best>=p) count++;
      }
      result=Math.max(result,count);
    }
    return result;
  }
  private static int recursiveApproach1(int N, int S, int p, int[] t) {
    return Math.max(0,recursiveApproach1(N,S,p,t,0));
  }
  private static int recursiveApproach1(int N, int S, int p, int[] t, int k) {
    if (k==N) return S==0?0:-N*2;
    int result=-N*2;
    if (S>0) { // Surprissing
      int best=-1;
      for (int u=0; u<=10; u++) for (int v=0; v<=10; v++) for (int w=0; w<=10; w++) if (u+v+w==t[k]) {
        int max=Math.max(u,Math.max(v,w));
        int min=Math.min(u,Math.min(v,w));
        if (max-min==2) best=Math.max(best,max);
      }
      result=Math.max(result,(best>=p?1:0)+recursiveApproach1(N,S-1,p,t,k+1));
    }
    { // Not surprissing
      int best=-1;
      for (int u=0; u<=10; u++) for (int v=0; v<=10; v++) for (int w=0; w<=10; w++) if (u+v+w==t[k]) {
        int max=Math.max(u,Math.max(v,w));
        int min=Math.min(u,Math.min(v,w));
        if (max-min<=1) best=Math.max(best,max);
      }
      result=Math.max(result,(best>=p?1:0)+recursiveApproach1(N,S,p,t,k+1));
    }
    return result;
  }
  private static int recursiveApproach2(int N, int S, int p, int[] t) {
    return Math.max(0,recursiveApproach2(N,S,p,t,0));
  }
  private static int recursiveApproach2(int N, int S, int p, int[] t, int k) {
    if (k==N) return S==0?0:-N*4;
    int result=-N*4,sum=t[k];
    if (S>0) {
      // Surprissing
      int best=(sum>=2&&sum<=28?(sum+4)/3:-1);
      if (best!=-1) result=Math.max(result,(best>=p?1:0)+recursiveApproach2(N,S-1,p,t,k+1));
    }
    // Not surprissing
    int best=(sum+2)/3;
    result=Math.max(result,(best>=p?1:0)+recursiveApproach2(N,S,p,t,k+1));
    return result;
  }
  private static int dynamicProgrammingApproach1(int N, int S, int p, int[] t) {
    int table[][]=new int[N+1][S+1];
    for (int k=N; k>=0; k--) for (int s=0; s<=S; s++) {
      if (k==N) {
        table[k][s]=(s==0?0:-N*4);
      }
      else {
        int result=-N*4,sum=t[k];
        if (s>0) {
          // Surprissing
          int best=(sum>=2&&sum<=28?(sum+4)/3:-1);
          if (best!=-1) result=Math.max(result,(best>=p?1:0)+table[k+1][s-1]);
        }
        // Not surprissing
        int best=(sum+2)/3;
        result=Math.max(result,(best>=p?1:0)+table[k+1][s]);
        table[k][s]=result;
      }
    }
    return Math.max(0,table[0][S]);
  }
  private static int dynamicProgrammingApproach2(int N, int S, int p, int[] t) {
    int array[]=new int[S+1];
    Arrays.fill(array,-N*4);
    array[0]=0;
    for (int k=N-1; k>=0; k--) for (int s=S; s>=0; s--) {
      int result=-N*4,sum=t[k];
      if (s>0) {
        // Surprissing
        int best=(sum>=2&&sum<=28?(sum+4)/3:-1);
        if (best!=-1) result=Math.max(result,(best>=p?1:0)+array[s-1]);
      }
      // Not surprissing
      int best=(sum+2)/3;
      result=Math.max(result,(best>=p?1:0)+array[s]);
      array[s]=result;
    }
    return Math.max(0,array[S]);
  }
}
