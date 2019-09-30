import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int[] t = new int[N];
    for(int i = 0; i < N; i++){
      t[i] = scanner.nextInt();
    }
    int time = 0;
    int ans = Integer.MAX_VALUE;
    for(int i = 0; i < (1 << N); i++){
      int timeA = 0;
      int timeB = 0;
      for(int j = 0; j < N; j++){
        if((i>>j & 1) == 1){
          timeA += t[j];
        }else{
          timeB += t[j];
        }
      }
      time = Math.max(timeA, timeB);
      ans = Math.min(time, ans);
    }
    System.out.println(ans);
	}
}