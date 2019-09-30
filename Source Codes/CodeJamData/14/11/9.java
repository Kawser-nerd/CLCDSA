import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class ChargingChaos {
	static final String fileName = "A-large";
	
	ChargingChaos(){
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for(int t = 1; t<=tests; t++){
			int N, L;
			N = in.nextInt();
			L = in.nextInt();
			String[] outlet = new String[N];
			for(int i = 0; i<N; i++)
				outlet[i] = in.next();
			String[] req = new String[N];
			for(int i = 0; i<N; i++)
				req[i] = in.next();
			int min = L+1;
			Loop: for(int i = 0; i<N; i++){
				long isFlip = 0;
				for(int j = 0; j<L; j++)
					if(req[0].charAt(j) != outlet[i].charAt(j))
						isFlip |= 1L << j;
				if(Long.bitCount(isFlip) >= min)
					continue;
				boolean[] used = new boolean[N];
				for(int j = 0; j<N; j++){
					String res = "";
					for(int k = 0; k<L; k++)
						if((isFlip & (1L<<k)) == 0)
							res += outlet[j].charAt(k);
						else res += (outlet[j].charAt(k) == '0' ? '1':'0');
					boolean found = false;
					for(int k = 0; k<N; k++)
						if(!used[k] && res.equals(req[k])){
							found = true;
							used[k] = true;
							break;
						}
					if(!found)
						continue Loop;
				}
				min = Long.bitCount(isFlip);
			}
			System.out.printf("Case #%d: %s\n", t, min > L ? "NOT POSSIBLE" : min);
		}
		in.close();
	}
	
	public static void main(String[] args) throws Exception{
		String root = "C:/Users/Tyler/Downloads/";
		String file = ChargingChaos.fileName;
		System.setIn(new FileInputStream(new File(root+file+".in")));
		System.setOut(new PrintStream(new File(root+file+".out")));
		new ChargingChaos();
	}
}
