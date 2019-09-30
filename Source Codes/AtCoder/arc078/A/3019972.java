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
      ArrayList<Long> l = new ArrayList<Long>();
      for(int i = 0; i<N; i++){
        long c = Long.parseLong(sc.next());
        if(i == 0) l.add(c);
        else{
          long p = l.get(i-1);
          l.add(c+p);
        }
      }
      long diff = Long.MAX_VALUE;
      for(int i = 0; i<N-1; i++){
          long arai = l.get(N-1)-l.get(i);
          long d = Math.abs(l.get(i)-arai);
          diff = Math.min(diff,d);
      }
      System.out.println(diff);
  }
}