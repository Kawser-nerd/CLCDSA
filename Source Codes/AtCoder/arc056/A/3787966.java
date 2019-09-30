import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    long A = scanner.nextLong();
    long B = scanner.nextLong();
    long K = scanner.nextLong();
    long L = scanner.nextLong();
    long ans = 0;
    if(K % L == 0){
      ans = (K/L) * B;
    }else if(K % L != 0){
      ans = Math.min((L+K-1)/L * B, (K/L) * B + (K-(K/L)*L) * A);
    }
    System.out.println(ans);
  }
}