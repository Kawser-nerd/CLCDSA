import java.util.*;
import java.lang.*;

class Pair implements Comparable<Pair>{
  int a;
  int cnt;
  public Pair(int i, int j){
    this.a = i;
    this.cnt = j;
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
      HashMap<Integer,Pair> map = new HashMap<>();
      ArrayList<Pair> l = new ArrayList<>();
      for(int i = 0; i<N; i++){
        int c = Integer.parseInt(sc.next());
        for(int j = 0; j<3; j++){
          if(j == 1) c--;
          else if(j == 2) c+=2;
          //System.out.println("i,c = "+i+" "+c);
          if(!map.containsKey(c)){
             Pair p = new Pair(c,1);
             map.put(c, p);
             l.add(p);
          }else{
            Pair p = map.get(c);
            p.cnt++;
          }
        }
      }
      Collections.sort(l);
      Pair res = l.get(l.size()-1);
      System.out.println(res.cnt);
  }
}