import java.io.*;
import java.util.*;

public class chain {
	public static void main (String[] args) throws IOException{
		BufferedReader in=new BufferedReader(new FileReader("chain.in"));
		PrintWriter out=new PrintWriter(new FileWriter("chain.out"));
		int test=Integer.parseInt(in.readLine());
		for (int i=1; i<=test; i++){
			out.print("Case #"+i+": ");
			StringTokenizer st=new StringTokenizer(in.readLine());
			int switches=(int)Math.pow(2, Integer.parseInt(st.nextToken()));
			int claps=Integer.parseInt(st.nextToken());
			if ((claps+1)%switches==0)
				out.println("ON");
			else
				out.println("OFF");
		}
		out.close();
		System.exit(0);
	}
}
