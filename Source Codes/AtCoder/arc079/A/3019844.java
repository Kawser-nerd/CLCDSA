import java.util.*;
import java.lang.*;

// class Pair implements Comparable<Pair>{
//   long a;
//   int cnt;
//   public Pair(long i, int j){
//     this.a = i;
//     this.cnt = j;
//   }
//   public int compareTo(Pair p){
//     if(this.cnt>=2 && p.cnt >=2 && this.a<p.a) return -1;
//     if(this.cnt<2 && p.cnt>=2) return -1;
//     return 1;
//   }
// }

class Main{
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int N = Integer.parseInt(sc.next());
      int M = Integer.parseInt(sc.next());
      boolean[] ar = new boolean[N];
      boolean[] br = new boolean[N];
      for(int i = 0; i<M; i++){
        int s = Integer.parseInt(sc.next())-1;
        int g = Integer.parseInt(sc.next())-1;
        if(s == 0) ar[g] = true;
        else if(g == N-1) br[s] = true;
      }
      for(int i = 0; i<N; i++){
        if(ar[i] && br[i]){
          System.out.println("POSSIBLE");
          return;
        }
      }
      System.out.println("IMPOSSIBLE");
  }
}