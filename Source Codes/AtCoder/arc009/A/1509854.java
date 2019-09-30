import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
		int number = Integer.parseInt(br.readLine());
		int sum = 0;
		for(int i=0;i<number;i++) {
			String[] setting = br.readLine().split(" ");
			int num = Integer.parseInt(setting[0]);
			int price = Integer.parseInt(setting[1]);
			sum = sum + num * price;
		}
		System.out.println((int) (sum * 1.05));
	}
}