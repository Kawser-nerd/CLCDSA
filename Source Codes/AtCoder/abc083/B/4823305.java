import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String str = bfr.readLine();
		String[] wa = str.split(" ");
		int N = Integer.parseInt(wa[0]);
		int a = Integer.parseInt(wa[1]);
		int b = Integer.parseInt(wa[2]);
		int sum = 0;
		for(int i=1; i<=N; i++) {
			int tmpSum = 0;
			int num = i;
			while(num != 0) {
				tmpSum += num %10;
				num /= 10;
			}
			if(tmpSum >= a && tmpSum <= b) {
				sum += i;
			}
		}
		System.out.println(sum);
	}
}