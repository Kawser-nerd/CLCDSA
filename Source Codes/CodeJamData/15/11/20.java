import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class mushroom {
	public static void main(String[] args) throws IOException{
		BufferedReader buf = new BufferedReader(new FileReader("mushroom.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("mushroom.out")));
		Long n = Long.parseLong(buf.readLine());
		for(int i = 1; i <= n; i++){
			Long m = Long.parseLong(buf.readLine());
			String[] s = buf.readLine().split(" ");
			long fsum = 0;
			long largest = 0;
			for(int j = 1; j < m; j++){
				if(Long.parseLong(s[j]) - Long.parseLong(s[j-1]) < 0){
					fsum = fsum + Long.parseLong(s[j-1]) - Long.parseLong(s[j]);
					if(Long.parseLong(s[j-1]) - Long.parseLong(s[j]) > largest) largest = Long.parseLong(s[j-1]) - Long.parseLong(s[j]);
				}
			}
			long nsum = 0;
			for(int j = 0; j < m-1; j++){
				nsum = nsum + Math.min(Long.parseLong(s[j]), largest);
			}
			out.println("Case #" + i + ": " + fsum + " " + nsum); 
		}
		buf.close();
		out.close();
	}
}
