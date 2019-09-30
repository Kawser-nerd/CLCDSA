import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    Map<String, Integer> map = new HashMap<>();
    int n = sc.nextInt();
    for(int i = 0; i < n; i++){
      String str = sc.next();
      if(!map.containsKey(str)){
        map.put(str, 0);
      }
      map.put(str, map.get(str) + 1);
    }
    int m = sc.nextInt();
    for(int i = 0; i < m; i++){
      String str = sc.next();
      if(!map.containsKey(str)){
        map.put(str, 0);
      }
      map.put(str, map.get(str) - 1);
    }
    int max = 0;
    for(int i : map.values()){
      max = max > i ? max : i;
    }
    System.out.println(max);
  }
}