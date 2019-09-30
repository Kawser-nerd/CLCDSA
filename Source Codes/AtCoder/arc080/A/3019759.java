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
      int cnt4 = 0;
      int cnt2 = 0;
      int odd = 0;
      int N = Integer.parseInt(sc.next());
      for(int i = 0; i<N; i++){
        long a = Long.parseLong(sc.next());
        if(a%2 == 0){
          a/= 2;
          if(a%2 == 0) cnt4++;
          else cnt2++;
        }
        else odd++;
      }
      if(cnt2==0 && odd <= cnt4+1) System.out.println("Yes");
      else if(cnt2>0 && odd<=cnt4) System.out.println("Yes");
      else System.out.println("No");

  }
}