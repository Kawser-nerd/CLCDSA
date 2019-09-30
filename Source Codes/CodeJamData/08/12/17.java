import java.io.*;
import java.util.*;
import java.math.BigInteger;
import java.math.BigDecimal;

public class milk2{
	public static void main(String[] args) throws Exception{
		BufferedReader fin = new BufferedReader(new FileReader("milk.in"));

		String in = fin.readLine();

		int T = Integer.parseInt(in);
		
		for(int casenum=1; casenum<=T; casenum++){
			in = fin.readLine();
			int n = Integer.parseInt(in);

			in = fin.readLine();
			int m = Integer.parseInt(in);

			boolean[][] cust = new boolean[m][2*n];
			int[] malts = new int[m];

			for(int c1=0; c1<m; c1++){
				malts[c1] = -1;
			}

			for(int c1=0; c1<m; c1++){
				in = fin.readLine();

				String[] sp = in.split(" ");

				for(int c2=1; c2<sp.length; c2+=2){
					int a = Integer.parseInt(sp[c2])-1;
					int b = Integer.parseInt(sp[c2+1]);

					if(b==1){
						malts[c1] = a;
					} else{
						cust[c1][a] = true;
					}
					
					
				}
			}

			ArrayList<Integer> forcedmalt = new ArrayList<Integer>();
			boolean impossible = false;
	
			for(int c1=0; c1<m && !impossible; c1++){
				if(malts[c1] != -2){
				boolean likesnone = true;
				for(int c2=0; c2<n; c2++){
					if(cust[c1][c2] == true)
						likesnone = false;
				}

				if(likesnone){
					
					if(malts[c1] == -1){
						impossible = true;
					} else{
						forcedmalt.add(malts[c1]);
						for(int c3=0; c3<m; c3++){
							cust[c3][malts[c1]] = false;
						}
						malts[c1] = -2;
						c1 = -1;
					}

					
				}
				}
			}

			String outstring = "";
			if(impossible){
				outstring = "IMPOSSIBLE";
			} else{
				boolean[] needed = new boolean[n];
				for(int c1=0; c1<forcedmalt.size(); c1++){
					needed[forcedmalt.get(c1)] = true;
				}

				for(int c1=0; c1<n; c1++){
					if(needed[c1]){
						outstring += "1 ";
					} else
						outstring += "0 ";
				}
			}

			System.out.println("Case #" + casenum + ": " + outstring);
		}
	}
}

