import java.util.*;
import java.lang.*;

class Main{
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int N = Integer.parseInt(sc.next());
      HashMap<Integer,Integer> map = new HashMap<>();
      for(int i = 0; i<N; i++){
        int c = Integer.parseInt(sc.next());
        if(!map.containsKey(c)) map.put(c,1);
        else{
          int num = map.get(c);
          map.put(c,++num);
        }
      }
      long res = 0;
      for(Map.Entry<Integer, Integer> entry : map.entrySet()){
        int c = entry.getKey();
        int cnt = entry.getValue();
        if(cnt<c) res+=cnt;
        else res+=(cnt-c);
      }
      System.out.println(res);
  }
}