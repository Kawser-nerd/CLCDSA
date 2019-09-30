import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;


public class TicTacToeTomek {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new FileReader(new File("in")));
		BufferedWriter bw=new BufferedWriter(new FileWriter(new File("out")));
		StringTokenizer st;
		int T=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=T;cn++){
			int arr[][]=new int[4][4];
			for(int i=0;i<4;i++){
				String line=br.readLine();
				for(int j=0;j<4;j++){
					char c=line.charAt(j);
					if(c=='.')
						arr[i][j]=0;
					else if(c=='O')
						arr[i][j]=2;
					else if(c=='X')
						arr[i][j]=3;
					else if(c=='T')
						arr[i][j]=1;
				}
			}
			br.readLine();
			boolean owin=false;
			boolean xwin=false;
			boolean full=true;
			//check if full
			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++)
					full&=arr[i][j]!=0;
			//check for winner
			//down
			for(int i=0;i<4;i++){
				int p2=1;
				for(int j=0;j<4;j++){
					p2*=arr[i][j];
				}
				if(p2==8||p2==16)
					owin=true;
				if(p2==27||p2==81)
					xwin=true;
			}
			//right
			for(int j=0;j<4;j++){
				int p2=1;
				for(int i=0;i<4;i++){
					p2*=arr[i][j];
				}
				if(p2==8||p2==16)
					owin=true;
				if(p2==27||p2==81)
					xwin=true;
			}
			//diagonal
			int p1=1;
			int p2=1;
			for(int k=0;k<4;k++){
				p1*=arr[k][k];
				p2*=arr[3-k][k];
			}
			if(p1==8||p1==16)
				owin=true;
			if(p1==27||p1==81)
				xwin=true;
			if(p2==8||p2==16)
				owin=true;
			if(p2==27||p2==81)
				xwin=true;
			
			//print
			if(owin)
				bw.append("Case #"+cn+": O won\n");
			else if(xwin)
				bw.append("Case #"+cn+": X won\n");
			else if(full)
				bw.append("Case #"+cn+": Draw\n");
			else
				bw.append("Case #"+cn+": Game has not completed\n");
			System.out.println(cn+" "+owin+" "+xwin+" "+full);
		}
		bw.flush();
		
	}

}
