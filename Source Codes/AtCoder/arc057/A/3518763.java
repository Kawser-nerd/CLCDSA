import java.util.Scanner;

public class Main {
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
		long A = scan.nextLong();
		long K = scan.nextLong();
		scan.close();
    long  lim = 2_000_000_000_000L;
    long day = 0;
    if(K == 0){
      System.out.println(lim - A );
      return;
    }

    while( lim > A){
      A += 1+(A*K);
      day++;
    }

    System.out.println(day);

  }
}