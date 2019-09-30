import java.util.*;
 
public class Main{
  public static int[] dp;
  public static void main(String[]args){
    Scanner sc =  new Scanner(System.in);
    int N = Integer.parseInt(sc.nextLine());
    List<Integer> list = new ArrayList<>();
    for(int i = 0; i < N; i++){
      list.add(Integer.parseInt(sc.nextLine()));
    }
    Collections.sort(list, Collections.reverseOrder());
    
    Double ans = 0.0;
    for(int i=0; i < N; i++){
      if(i % 2 == 0){
        ans += list.get(i) * list.get(i) * Math.PI;
      }else{
        ans -= list.get(i) * list.get(i) * Math.PI;
      }
    }
    
    System.out.println(ans);
  }
}