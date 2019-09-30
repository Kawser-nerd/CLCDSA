import java.util.Scanner;
import java.util.Arrays;

public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int[] C = new int[N];
    for(int i = 0; i < N; i++){
      C[i] = scanner.nextInt();
    }
    Arrays.sort(C);
    int[] num = new int[N];
    for(int i = 0; i < N; i++){
      for(int j = 0; j < i; j++){
        if(C[i] != C[j] && C[i] % C[j] == 0){
          num[i]++;
        }
      }
      for(int j = 0; j < N; j++){
        if(i != j && C[i] == C[j]){
          num[i]++;
        }
      }
    }
    double ans = 0;
    double kosuu = 0;
    for(int i = 0; i < N; i++){
      kosuu = (num[i]+2)/2;
      ans += kosuu/(num[i]+1);
    }
    System.out.println(ans);
  }
}