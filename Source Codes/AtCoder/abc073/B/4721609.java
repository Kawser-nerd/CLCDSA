import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] a) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.valueOf(in.readLine());
		String[] l;
		int total = 0;
		for(int i = 0; i < n; i++) {
			l = in.readLine().split(" ");
			total+=Integer.valueOf(l[1])-Integer.valueOf(l[0])+1;
		}
        System.out.println(total);
	}
}