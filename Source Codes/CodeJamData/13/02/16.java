import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;


public class Lawnmower {

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
			st=new StringTokenizer(br.readLine());
			int N=Integer.parseInt(st.nextToken());
			int M=Integer.parseInt(st.nextToken());
			int arr[][]=new int[N][M];
			for(int i=0;i<N;i++){
				st=new StringTokenizer(br.readLine());
				for(int j=0;j<M;j++){
					arr[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			//look if there are contradictions
			boolean okay=true;
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++){
					int h=arr[i][j];
					//vertical
					boolean ok1=true;
					for(int k=0;k<N;k++)
						ok1&=arr[k][j]<=h;
					//horizontal
					boolean ok2=true;
					for(int k=0;k<M;k++)
						ok2&=arr[i][k]<=h;
					if(!(ok1||ok2))
						okay=false;
				}
			}
			if(okay)
				bw.append("Case #"+cn+": YES\n");
			else
				bw.append("Case #"+cn+": NO\n");
		}
		bw.flush();

	}

}
