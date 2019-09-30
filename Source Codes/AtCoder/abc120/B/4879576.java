import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int K = sc.nextInt();
    int M = Math.min(A, B);
    List<Integer> list = new ArrayList<>();
    for(int i=1; i<=M; i++){
      if(A%i==0 && B%i==0){
        list.add(i);
      }
    }
    System.out.print(list.get(list.size() - K));
  }
}