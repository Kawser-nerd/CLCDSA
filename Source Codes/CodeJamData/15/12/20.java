import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class Barber {
	public static void main(String[] args) throws IOException{
		BufferedReader buf = new BufferedReader(new FileReader("barber.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("barber.out")));
		int q = Integer.parseInt(buf.readLine());
		for(int i = 1; i <= q; i++){
			String[] s = buf.readLine().split(" ");
			int b = Integer.parseInt(s[0]);
			int n = Integer.parseInt(s[1]); //assuming n > b
			String[] time = buf.readLine().split(" ");
			double rate = 0;
			for(int j = 0; j < b; j++){
				rate = rate + 1d / Double.parseDouble(time[j]);
			}
			int r = n - b;
			long l = Math.round(r/rate);
			long h = l + 100000;
			while(true){
				long m = (l + h)/2;
				long cuts = 0;
				long exact = 0;
				for(int j = 0; j < b; j++){
					cuts = cuts + m / Long.parseLong(time[j]);
					if(m % Long.parseLong(time[j]) == 0) exact++;
				}
				if(cuts >= r && cuts - exact < r) break;
				if(cuts >= r) h = m;
				else if (cuts - exact < r) l = m;
				else System.out.println("Hello");
			}
			long t = (l + h)/2;
			long total = 0;
			for(int j = 0; j < b; j++){
				total = total + (t-1)/ Long.parseLong(time[j]);
			}
			long rem = r - total;
			for(int j = 0; j < b; j++){
				if(t % Long.parseLong(time[j]) == 0){
					rem--;
					if(rem == 0) {
						out.println("Case #" + i + ": " + (j+1));
						break;
					}
				}
			}
		}
		buf.close();
		out.close();
	}
}
