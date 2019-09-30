import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class qualA {
public static void main(String[] args) {
		String prblm="A"; boolean fl=!true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int T=Integer.parseInt(s);
			for (int i = 1; i <= T; i++) {
				s=fr.readLine();
				boolean[] crd=new boolean[16];
				int f=Integer.parseInt(s);
				for (int j = 1; j <= 4; j++) {
					s=fr.readLine();
					if (j==f){
						String[] tok=s.split(" ");
						for (int k = 0; k < tok.length; k++) 
							crd[Integer.parseInt(tok[k])-1]=true;					
					}
				}
				s=fr.readLine();
				int c=Integer.parseInt(s);
				int nc=0, res=-1;
				for (int j = 1; j <= 4; j++) {
					s=fr.readLine();
					if (j==c){
						String[] tok=s.split(" ");
						for (int k = 0; k < tok.length; k++){ 
							if (crd[Integer.parseInt(tok[k])-1]){
								nc++; res=Integer.parseInt(tok[k]);								
							}
						}
					}
				}
				if (nc==0) s="Volunteer cheated!";
				else if (nc>1) s="Bad magician!";
				else s=""+res;
				System.out.println(nc+" "+res+" "+s);
				fw.write("Case #"+i+": "+ s  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}