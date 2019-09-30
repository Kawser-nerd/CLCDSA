import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args)throws Exception {
		InputStreamReader is = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader (is);
		String input[] = br.readLine().split(" ");
		int count = Integer.parseInt(input[0]);
		int maxLength =  Integer.parseInt(input[1]);
		String input2[] =br.readLine().split(" ");
		ArrayList<Integer> result = new ArrayList<Integer>();
		for(int i=0; i<count; i++) {
			if(i+1 >= count) {
				break;
			}
			int num =Integer.parseInt(input2[i]);
			int num2 =Integer.parseInt(input2[i+1]);
			if(num+num2 >= maxLength) {
				for(int j=0 ; j<i;j++) {
					result.add(j+1);
				}
				for(int n=count-1 ; n>i+1;n--) {
					result.add(n);
				}
				result.add(i+1);
				System.out.println("Possible");
				for(int re:result) {
					System.out.println(re);
				}
				return;
			}
		}
		System.out.println("Impossible");
	}
}