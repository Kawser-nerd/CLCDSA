import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int M = scanner.nextInt();
    for(int i = 1; i <= N; i++){
      if(i != M){
        System.out.println(i);
        break;
      }
    }
  }
}