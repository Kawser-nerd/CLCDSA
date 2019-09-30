import java.io.BufferedReader;
import java.io.InputStreamReader;
public class Main {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine());

		long counter = 0;
		int amari = 0;
		for(int i = 0; i < num; i++){
			int A = Integer.parseInt(br.readLine());
			if(amari > 0 && A > 0){
				A += 1;
			}
			counter += A / 2;
			amari = A % 2;
		}
		System.out.println(counter);
	}
}