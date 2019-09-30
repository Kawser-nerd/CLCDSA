import java.util.*;

public class Main {
 
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.next());
    HashSet<Integer> set = new HashSet<>(N);
    for(int i = 0; i < N; i++){
      int A = Integer.parseInt(sc.next());
      if(set.contains(A))
        set.remove(A);
      else
        set.add(A);
    }
    System.out.println(set.size());
  }
  
}