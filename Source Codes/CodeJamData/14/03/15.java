import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class qualC {
public static void main(String[] args) {
		String prblm="C"; boolean fl=true;
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
				int R=Integer.parseInt(tok[0]);
				int C=Integer.parseInt(tok[1]);
				int M=Integer.parseInt(tok[2]);
				int MR=R*C-M;
				char[][] mt=new char[R][C];
				for (int j = 0; j < R; j++)
					for (int k = 0; k < C; k++) mt[j][k]='*';
				boolean b=(R>=C);				
				if (MR>1) {
					if (Math.min(R,C)==1){
						for (int j = 1; j < R*C-M; j++) {
							if (b) mt[j][0]='.';
							else mt[0][j]='.';
						}											
					}
					else if ((Math.min(R,C)==2 && MR%2!=0) || MR<4 || MR==5 || MR==7) 
						mt[0][0]=0;
					else{
						if (MR>=Math.min(R,C)*2+2){
							int nn=MR/Math.min(R,C);
							int nr=MR%Math.min(R,C);
							for (int j = 0; j < ((b)?C:R); j++) {
								for (int k = 0; k < nn; k++) {
									if (nr==1 && k==nn-1 && j==((b)?C:R)-1) 
										continue;
									if (b) mt[k][j]='.';
									else mt[j][k]='.';
								}
								if (nr>0 && j<Math.max(nr,2)){
									if (b) mt[nn][j]='.';
									else mt[j][nn]='.';
								}
							}
						}
						else{
							int nn=MR/2;
							if (MR%2!=0) {
								nn--;
								for (int j = 0; j < 3; j++) {
									if (b) mt[2][j]='.';
									else mt[j][2]='.';
								}
							}
							for (int j = 0; j < nn; j++) {
								if (b) {mt[0][j]=mt[1][j]='.';}
								else {mt[j][0]=mt[j][1]='.';}
							}
						}
					}
				}
				if (mt[0][0]==0) s="Impossible\n";
				else {					
					mt[0][0]='c'; s="";
					for (int j = 0; j < R; j++){
						for (int k = 0; k < C; k++) s+=mt[j][k];
						s+="\n";
					}
				}				
				System.out.print(s);
				fw.write("Case #"+i+":\n"+ s);
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}