import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class ChargingChaos {
	public static void main(String[]Args) throws FileNotFoundException{
		Scanner sc = new Scanner(new File("A-large (1).in"));
		PrintWriter out = new PrintWriter(new File("things.out"));
//		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt(),cc=0;
		while(t-->0){
			int n = sc.nextInt();
			int l = sc.nextInt();

			long[] things = new long[n];
			long[] things2 = new long[n];
			HashSet<Long> hs = new HashSet<Long>();
			for(int k = 0; k < n;k++)
				things[k]= make(sc.next());
			for(int k = 0; k < n;k++){
				things2[k]= make(sc.next());
				hs.add(things2[k]);
			}
			int ans = l+1;
			for(int k = 0; k < n; k++){
				long swit = things[0]^things2[k];
				boolean good =true;
				for(int j = 0;good && j < n;j++)
					if(!hs.contains(things[j] ^ swit))
						good = false;
				if(good)
					ans = Math.min(Long.bitCount(swit),ans);
			}
			if(ans!=l+1)
				out.printf("Case #%d: %d%n",++cc, ans);
			else
				out.printf("Case #%d: NOT POSSIBLE%n",++cc);
			
		}
		out.close();
	}

	private static long make(String s) {
		return Long.parseLong(s, 2);
	}
}
