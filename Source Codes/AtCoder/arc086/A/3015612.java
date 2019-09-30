import java.util.*;
import java.lang.*;

class Pair implements Comparable<Pair>{
  int i;
  int cnt;
  public Pair(int a, int b){
      this.i = a;
      this.cnt = b;
  }
  public int compareTo(Pair p){
    if(this.cnt == p.cnt) return 0;
    if(this.cnt<p.cnt) return -1;
    return 1;
  }
}

class Main{
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int N = Integer.parseInt(sc.next());
      int K = Integer.parseInt(sc.next());
      HashMap<Integer, Pair> map = new HashMap<>();
      LinkedList<Pair> l = new LinkedList<>();
      for(int i = 0; i<N; i++){
        int c = Integer.parseInt(sc.next());
        if(!map.containsKey(c)){
          Pair p = new Pair(c,1);
          l.add(p);
           map.put(c, p);
         }
        else{
          Pair p = map.get(c);
          p.cnt++;
          map.put(c,p);
        }
      }
      Collections.sort(l);
      int size = l.size();
      if(size<=K){
        System.out.println(0);
        return;
      }
      long num = 0;
      for(int i = 0; i<K; i++){
          Pair cur =  l.get(size-i-1);
          num+=cur.cnt;
      }
      System.out.println(N-num);
  }
}