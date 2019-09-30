import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class R1A {	
	
public static void main(String[] args) {
		String prblm="A"; boolean fl=true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int T=Integer.parseInt(s);
			for (int i = 1; i <= T; i++) {
				s=fr.readLine();
				String[] tok=s.split(" ");
				long r=Long.parseLong(tok[0]);
				long t=Long.parseLong(tok[1]);
				long mn=0, mx=2000000000l;
				while (mx-mn>0){
					long v=(mn+mx+1)/2;
					//System.out.println(v);
					if (Long.MAX_VALUE/(2*r+2*v-1)<v || v*(2*r+2*v-1) > t) mx=v-1;
					else mn=v;
				}
				System.out.println(mn);
				fw.write("Case #"+i+": "+ mn  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}