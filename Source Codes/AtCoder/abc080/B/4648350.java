import java.util.*;

public class Main{
  
	public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);
			int a = sc.nextInt();
			int n = a;
			int[] array = new int[8]; 
			int b = 10;
			int sum = 0;
			for(int i = 0; i < 8; i++) {
				array[i] = a % b;
				a -= array[i];
				sum += array[i] / (b / 10);
				b *= 10;
			}
			if(n % sum == 0) {
				System.out.println("Yes");
			}else {
				System.out.println("No");
			}
		
		}
	}