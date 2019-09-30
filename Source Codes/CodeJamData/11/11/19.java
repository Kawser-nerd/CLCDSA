import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.*;
import static java.lang.Math.*;
import static java.lang.Integer.parseInt;
import static java.lang.Double.parseDouble;
import static java.lang.Long.parseLong;
import static java.lang.System.*;
import static java.util.Arrays.*;
import static java.util.Collection.*;
public class A {
	static int gcd(int a, int b) {
		int c;
		if(a > b) {
			c = a;
			a = b;
			b = a;
		}
		while(a != 0) {
			c = b % a;
			b = a;
			a = c;
		}
		return b;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		int T = parseInt(br.readLine());
		for(int t = 0; t++ < T;) {
			String[] line = br.readLine().split(" ");
			int	N = Integer.parseInt(line[0]),
				PD= Integer.parseInt(line[1]),
				PG= Integer.parseInt(line[2]);
			int gcd = gcd(PD, 100);
			int den = 100 / gcd;
			if(den <= N && (PG != 100 || PD == 100) && (PG != 0 || PD == 0))
				System.out.println("Case #" + t + ": Possible");
			else
				System.out.println("Case #" + t + ": Broken");
		}
	}
}
