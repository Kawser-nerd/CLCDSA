import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine());
		int tenNum = num/10;
		int remainder = num%10;
		int answer = 0;
		if(remainder*15 > 100) {
			answer = (tenNum + 1) * 100;
		}else {
			answer = tenNum*100+remainder*15;
		}
		System.out.println(answer);
	}
}