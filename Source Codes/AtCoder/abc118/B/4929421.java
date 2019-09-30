import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] data = sc.nextLine().split(" ");
		int N = Integer.parseInt(data[0]);
		int M = Integer.parseInt(data[1]);
		int[] food = new int[M];
		for(int i=0;i<M;i++) {
			food[i]=0;
		}
		
		for(int i=0;i<N;i++) {
			data = sc.nextLine().split(" ");
			int K = Integer.parseInt(data[0]);
			for(int j=1;j<=K;j++) {
				int value = Integer.parseInt(data[j]);
				food[--value]++;
			}
		}
		
		int cnt=0;
		for(int i=0;i<M;i++) {
			if(food[i]==N) cnt++;
		}
    	System.out.println(cnt);
	}
}