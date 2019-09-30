import java.io.BufferedReader;
import java.io.InputStreamReader;
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		long count = 0;
		int mod =0;
		for (int i = 0; i < n; i++) {
			int a1 = Integer.parseInt(br.readLine());
			if(a1>0){
				a1+=mod;
				count += (a1 / 2);
				mod=a1%2;
			}else {
				mod=0;
			}
		}
		System.out.println(count);
	}
}