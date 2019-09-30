package r1a;

import java.util.*;

public class C {
  public static void main(String[] args) {
    long comb[][] = new long[41][41];
    comb[0][0] = 1;
    for(int n = 1 ; n < comb.length ; n++){
      comb[n][0] = 1;
      for(int m = 1 ; m < comb.length ; m++){
        comb[n][m] = comb[n - 1][m] + comb[n - 1][m - 1];
      }
    }
    
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int t = 1 ; t <= T ; t++){
      int C = sc.nextInt();
      int N = sc.nextInt();
      double exp[] = new double[C + 1];
      double probs[] = new double[C + 1];
      probs[0] = 1.0;
      probs[N] = 1.0;
      for(int e = 1 ; e < C ; e++){
        if(e < N)continue;
        double same = comb[e][N] * 1.0 / comb[C][N];
        double other = (1.0 - same);
        for(int x = 1 ; x <= N ; x++){
          if(e + x > C)continue;
          double prob = (comb[C - e][x] * 1.0 / comb[C][N]) * comb[e][N - x];
          prob /= other;
          probs[e + x] += probs[e] * prob;
        }
      }
//      System.out.println(Arrays.toString(probs));
      exp[0] = 0.0;
      exp[N] = 1.0;
      for(int e = 1 ; e < C ; e++){
        if(e < N)continue;
        double same = comb[e][N] * 1.0 / comb[C][N];
        double other = (1.0 - same);
        double wtime = 1.0 / (1.0 - same);
        double et = exp[e];
        double net = (et + wtime);
//        System.out.println(net);
        for(int x = 1 ; x <= N ; x++){
          if(e + x > C)continue;
          double prob = (comb[C - e][x] * 1.0 / comb[C][N]) * comb[e][N - x];
          prob /= other;
//          System.out.println(prob+" "+probs[e + x]);
          exp[e + x] += net * prob * (probs[e] / probs[e + x]);
        }
//        System.out.println(Arrays.toString(exp));
      }
      System.out.printf("Case #%d: %.10f\n" , t , exp[C]);
    }
  }
}
