import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
      	String N = input.next();
      	int[] ns = new int[9];
      	for (int i = 0; i < 9; i++) {
          	int num = i + 1;
        	ns[i] = num * 100 + num * 10 + num;
        }
      	int ans = 1000;
      	
      	for (int i = 0; i < 9; i++) {
          if (ns[i] >= Integer.parseInt(N) && ns[i] < ans) {
              ans = ns[i];
          }
        }
		System.out.print(ans);

    }
  	
}