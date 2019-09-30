import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static int  count = 0;
	static long n;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		n = Long.parseLong(s);
		Main main = new Main();
		main.countk(3, true, false, false);
		main.countk(5, false, true, false);
		main.countk(7, false, false, true);
		System.out.println(count);
	}
	public static void countk(long k,boolean r3,boolean r5,boolean r7) {
		if(k>n)
			return;
		
		Main.countk(k*10+3, true, r5, r7);
		Main.countk(k*10+5, r3, true, r7);
		Main.countk(k*10+7, r3, r5, true);
		if(r3&&r5&&r7)
			count++;
	}
	
}