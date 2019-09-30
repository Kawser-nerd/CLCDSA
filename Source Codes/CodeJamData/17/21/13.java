import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.PriorityQueue;


public class Cruise {
	public static void main(String[] args) throws IOException{
		BufferedReader buf = new BufferedReader(new FileReader("cruise.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cruise.out")));
		int t = Integer.parseInt(buf.readLine());
		for(int i = 0; i < t; i++) {
			String[] s = buf.readLine().split(" ");
			int d = Integer.parseInt(s[0]);
			int n = Integer.parseInt(s[1]);
			double time = 0;
			//PriorityQueue<Pairs> dist = new PriorityQueue<Pairs>();
			for(int j = 0; j < n; j++){
				s = buf.readLine().split(" ");
				int init = Integer.parseInt(s[0]);
				int spd = Integer.parseInt(s[1]);
				if((d - init) / (double) spd > time) time = (d - init) / (double) spd;
				//dist.add(new Pairs(init, spd));
			}
			/*Pairs p = dist.poll();
			int pos = p.a;
			int mspd = p.b;
			while(!dist.isEmpty()){
				Pairs next = dist.poll();
				time += (next.a - pos) / ((double) mspd);
				mspd = Math.min(next.b, mspd);
				pos = next.a;
				System.out.println(i + " " + time);
			}
			time += (d - pos) / ((double) mspd);
			*/
			out.println("Case #" + (i + 1) + ": " + (d/time));
		}
		out.close();
	}
}
class Pairs implements Comparable<Pairs>{
	int a;
	int b;
	public Pairs(int x, int y){
		this.a = x;
		this.b = y;
	}
	public int compareTo(Pairs o) {
		return this.a - o.a;
	}
}
