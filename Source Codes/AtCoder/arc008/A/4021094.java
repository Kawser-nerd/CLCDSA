import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		if(N % 10 <= 6){
			System.out.println((N/10)*100 +(N-(N/10)*10)*15);
		}else{
			System.out.println(((N/10)+1)*100);
		}
  }
}