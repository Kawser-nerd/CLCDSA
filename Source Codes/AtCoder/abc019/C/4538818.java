import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.nextLine());
    String[] s =  sc.nextLine().split(" ");
    
    Set<Integer> set = new HashSet<>();
    for(int i = 0; i < N; i++){
      int A = Integer.parseInt(s[i]);
      while(A % 2 == 0){
           A /= 2;
      }
      set.add(A);
    }
    System.out.println(set.size());
  }
}