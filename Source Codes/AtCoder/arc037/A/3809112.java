import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int[] m = new int[N];
    int ans = 0;
    for(int i = 0; i < N; i++){
      m[i] = scanner.nextInt();
      if(m[i] < 80){
        ans += 80-m[i];
      }
    }
    System.out.println(ans);
  }
}