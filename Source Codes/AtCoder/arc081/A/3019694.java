import java.util.*;
import java.lang.*;

class Pair implements Comparable<Pair>{
  long a;
  int cnt;
  public Pair(long i, int j){
    this.a = i;
    this.cnt = j;
  }
  public int compareTo(Pair p){
    if(this.cnt>=2 && p.cnt >=2 && this.a<p.a) return -1;
    if(this.cnt<2 && p.cnt>=2) return -1;
    return 1;
  }
}

class Main{
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int N = Integer.parseInt(sc.next());
      HashMap<Long,Pair> map = new HashMap<>();
      ArrayList<Pair> l = new ArrayList<>();
      for(int i = 0; i<N; i++){
        long c = Long.parseLong(sc.next());
        if(!map.containsKey(c)){
           Pair p = new Pair(c,1);
           map.put(c, p);
           l.add(p);
        }else{
          Pair p = map.get(c);
          p.cnt++;
        }
      }
      Collections.sort(l);
      int size = l.size();
      Pair p1 = l.get(size-1);
      Pair p2 = l.get(size-2);
      long res = 0;
      if(p1.cnt>=4) res = p1.a*p1.a;
      else if(p1.cnt >= 2 && p2.cnt>=2) res = p1.a*p2.a;
      System.out.println(res);
  }
}