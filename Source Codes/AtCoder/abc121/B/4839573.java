import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int code =sc.nextInt();
		int code2 = sc.nextInt();
		int c = sc.nextInt();

		int[] b = new int[code2];
		int num = 0;
		int num2 =0;
		int sum = 0;
		int count = 0;

		for(int i = 0;i < code2;i++){
			b[i] = sc.nextInt();
		}

		for(int i = 0;i<code;i++){
			for(int j=0;j<code2;j++){
				num = sc.nextInt();
				num2 = b[j]*num;
				sum += num2;
			}
			if(sum + c > 0)
			count++;
			sum = 0;
		}

		System.out.println(count);
	}
}