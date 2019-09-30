import java.util.*;
 
public class Main{
  public static int[] dp;
  public static void main(String[]args){
    Scanner sc =  new Scanner(System.in);
    int N = Integer.parseInt(sc.nextLine());
    Set<Integer> set = new HashSet<>();
    int A = 0;
    int count = 0;
    for(int i = 0; i < N; i++){
      int B = Integer.parseInt(sc.nextLine());
      set.add(B);
      if(A == set.size()){
        count++;
      }
      A = set.size();
    }
    System.out.println(count);
  }
}