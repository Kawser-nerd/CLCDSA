import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
		long A = scan.nextLong();
		long B = scan.nextLong();
    long K = scan.nextLong();
    long L = scan.nextLong();
		scan.close();

    long ans = 0;
    if(K >= L){
      ans = B * (K/L);
      K %= L;
    }
    //System.out.println(ans);
    if(K*A <= B){
      ans += K*A;
    }else{
      ans += B;
    }

    System.out.println(ans);
  }
}