import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int[] n = new int[5];
    for(int i = 0; i < 5; i++){
      n[i] = sc.nextInt();
    }
    Set<Integer> set =  new HashSet<>();
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
        for(int k = 0; k < 5; k++){
          if(i != j && j != k && k != i){
            set.add(n[i] + n[j] + n[k]);
          }
        }
      }
    }
    
    
    List<Integer> list = new ArrayList<>(set);
    Collections.sort(list, Collections.reverseOrder());
    System.out.println(list.get(2));
  }
}