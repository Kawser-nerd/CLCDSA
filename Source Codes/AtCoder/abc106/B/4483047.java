import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
      	int A = input.nextInt();
      	int ans = 0;
      	for (int i = 1; i <= A; i+=2) {
          int count = 0;
          int j = 1;
          while (count < 10 && j <= i) {
          	if (i % j == 0) {
              count++;
            }
            j++;
          }
          if (count == 8) {
          	ans++;
          }
        	
        }
		System.out.print(ans);

    }
  
  	
}