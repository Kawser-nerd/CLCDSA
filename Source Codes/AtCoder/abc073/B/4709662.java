import java.util.*;
 
public class Main {
 
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.next());
    int count = 0;
    for(int i = 0; i < N; i++){
      int l = Integer.parseInt(sc.next());
      int r = Integer.parseInt(sc.next());
      count += r - l + 1;
    }
    System.out.println(count);
  }
  
}