import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int n = sc.nextInt();
		int k = sc.nextInt();
		
		List<Integer> r = new ArrayList<>();
		for(int i=0;i<n;i++) {
			r.add(sc.nextInt());
		}
		
		r.sort(null);
		
		
		double c = 0;
		for(int i=n-k;i<n;i++) {
			c = (c+r.get(i))/2;
			
		}
		
		out.println(c);

		sc.close();
	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}