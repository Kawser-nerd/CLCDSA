import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class R1C {
public static void main(String[] args) {
		String prblm="C"; boolean fl=!true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int T=Integer.parseInt(s);
			for (int i = 1; i <= T; i++) {
				fw.write("Case #"+i+":\n");
				s=fr.readLine();
				String[] tok=s.split(" ");
				int R=Integer.parseInt(tok[0]);
				int N=Integer.parseInt(tok[1]);
				int M=Integer.parseInt(tok[2]);
				int K=Integer.parseInt(tok[3]);
				for (int j = 0; j < R; j++) {
					s=fr.readLine();
					tok=s.split(" ");
					boolean[][][] fx=new boolean[6][6][6];
					for (int l = 2; l < 6; l++) {
						for (int h = l; h < 6; h++) {
							for (int p = h; p < 6; p++) {
								fx[l][h][p]=true;
							}
						}
					}
					for (int k = 0; k < K; k++) {
						int v=Integer.parseInt(tok[k]);
						if (v==1) continue;
						for (int l = 2; l < 6; l++) {
							for (int h = l; h < 6; h++) {
								for (int p = 0; p < 6; p++) {
									fx[l][h][p]&=((l*h*p)%v==0);
								}
							}
						}
					}
					boolean flg=true;
					for (int l = 2; l < 6 && flg; l++) {
						for (int h = l; h < 6 && flg; h++) {
							for (int p = h; p < 6 && flg; p++) {
								if (fx[l][h][p]){
									System.out.println(l+""+h+""+p);
									fw.write(l+""+h+""+p+"\n");
									flg=false;
								}
							}
						}
					}
				}				
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}