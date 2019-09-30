import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;


public class Enclosure {

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
			int K=Integer.parseInt(st.nextToken());
					
			int ans=K;
			for(int i=3;i<=N;i++){
				for(int j=3;j<=M;j++){
					int stones=2*(i-2)+2*(j-2);
					int covered=i*j-4;
					if(K<=covered)
						ans=Math.min(ans, stones);
					for(int k=1;k<=4;k++)
						if(K<=covered+k)
							ans=Math.min(ans, stones+k);
					if(i<N||j<M)
						if(K<=covered+2)
							ans=Math.min(ans, stones+1);
				}
			}
			System.out.println(N+" "+M+" "+K+" "+ans);
			bw.append("Case #"+cn+": ");
			bw.append(ans+"\n");
		}
		bw.flush();

	}

}
