import java.util.*;
 
public class Main {
 
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int X = sc.nextInt();
    HashSet<Integer> set = new HashSet<>(M);
    for(int i = 0; i < M; i++)
      set.add(sc.nextInt());
    int forward = 0, backward = 0;
    for(int i = X + 1; i < N; i++)
      if(set.contains(i))
        forward++;
    for(int i = X - 1; i > 0; i--)
      if(set.contains(i))
        backward++;
	System.out.println(Math.min(forward, backward));    
  }
  
}