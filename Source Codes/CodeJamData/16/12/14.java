import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Round1B {

	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter("B.txt");
		int T = Integer.parseInt(in.readLine());
		for(int c=1;c<=T;c++){
			int n = Integer.parseInt(in.readLine());
			int[] hcount = new int[2600];
			for(int i=0;i<2*n-1; i++){
				String[] spl = in.readLine().split(" ");
				for(int j=0;j<n;j++){
					hcount[Integer.parseInt(spl[j])]++;
				}
			}
			String ans = "";
			for(int i=1;i<=2500;i++){
				if(hcount[i]%2!=0){
					ans = ans+" "+i;
				}
			}
			pw.println("Case #"+c+":"+ans);
		}
		pw.close();
	}

}
