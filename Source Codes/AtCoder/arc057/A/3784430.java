import java.util.Scanner;
import java.util.Arrays;

public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    long A = scanner.nextLong();
    int K = scanner.nextInt();
    long money = A;
    long day = 0L;
    if(K > 0){
      while(money < 2000000000000L){
        money += money * K + 1;
        day++;
      }
    }else if(K == 0){
      day = 2000000000000L - A;
    }
    System.out.println(day);
  }
}