import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(stdin.readLine().replaceAll(" ", ""));
		int r = (int)Math.floor(Math.sqrt(n));
		String ans = n == r*r ? "Yes" : "No";
		System.out.println(ans);
	}

}