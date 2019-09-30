import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class qualB {
public static void main(String[] args) {
		String prblm="B"; boolean fl=true;
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
				double C=Double.parseDouble(tok[0]);
				double F=Double.parseDouble(tok[1]);
				double X=Double.parseDouble(tok[2]);
				double res=0;
				if (X<=C) res=X/2;
				else {
					res=C/2;
					double rate=2;
					while ((X-C)*(rate+F)>X*rate){
						rate+=F; res+=C/rate;
					}
					res+=(X-C)/rate;
				}
				System.out.println(res);
				fw.write("Case #"+i+": "+ res  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}