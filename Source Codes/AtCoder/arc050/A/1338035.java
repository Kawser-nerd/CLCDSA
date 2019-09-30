import java.io.*;

public class Main{
	public static void main( String[] args ) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] params = br.readLine().split( " " );
		String row = params[0].toLowerCase();
		if(row.equals( params[1] )){
			System.out.println( "Yes" );
		} else {
			System.out.println( "No" );
		}
	}
}