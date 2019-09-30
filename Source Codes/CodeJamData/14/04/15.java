import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class qualD {
	
	static double tol=1e-6;
public static void main(String[] args) {
		String prblm="D"; boolean fl=true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int T=Integer.parseInt(s);
			for (int i = 1; i <= T; i++) {
				s=fr.readLine();				
				int N=Integer.parseInt(s);
				double[] nw=new double[N];
				double[] kw=new double[N];
				s=fr.readLine();
				String[] tok=s.split(" ");
				for (int j = 0; j < tok.length; j++)
					nw[j]=Double.parseDouble(tok[j]);
				s=fr.readLine();
				tok=s.split(" ");
				for (int j = 0; j < tok.length; j++)
					kw[j]=Double.parseDouble(tok[j]);
				Arrays.sort(nw);
				Arrays.sort(kw);
				int ws=0, pk=0;
				for (int j = N-1; j >= 0; j--) {
					if (nw[j]>kw[j+pk]){ ws++; pk++;} 
				}
				int dws=0; pk=0;				
				for (int j = N-1; j >= 0; j--) {
					if (nw[j+pk]>kw[j]){ dws++;}
					else pk++;
				}
				System.out.println(dws+" "+ws);
				fw.write("Case #"+i+": "+ dws+" "+ws +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}