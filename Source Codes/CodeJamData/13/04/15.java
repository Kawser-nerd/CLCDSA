import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class Treasure {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new FileReader(new File("in")));
		BufferedWriter bw=new BufferedWriter(new FileWriter(new File("out")));
		StringTokenizer st;
		int Tt=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=Tt;cn++){
			st=new StringTokenizer(br.readLine());
			int Kk=Integer.parseInt(st.nextToken());
			N=Integer.parseInt(st.nextToken());
			keyst=new LinkedList<Integer>();
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<Kk;i++)
				keyst.add(Integer.parseInt(st.nextToken()));
			T=new int[N];
			K=new LinkedList[N];
			for(int i=0;i<N;i++){
				st=new StringTokenizer(br.readLine());
				T[i]=Integer.parseInt(st.nextToken());
				int kk=Integer.parseInt(st.nextToken());
				K[i]=new LinkedList<Integer>();
				for(int j=0;j<kk;j++){
					K[i].add(Integer.parseInt(st.nextToken()));
				}
			}
			lim=1<<N;
			dp=new int[lim];
			keys=new LinkedList[lim];
			path=new LinkedList[lim];
			dp[lim-1]=1;
			path[lim-1]=new LinkedList<Integer>();
			
			LinkedList<Integer> ans=find(0);
			
			bw.append("Case #"+cn+":");
			if(ans==null)
				bw.append(" IMPOSSIBLE");
			else
				while(!ans.isEmpty())
					bw.append(" "+ans.poll());
			bw.append("\n");
		}
		bw.flush();
	}
	static LinkedList<Integer> find(int bs){
//		System.out.println("find "+Integer.toBinaryString(bs));
		if(dp[bs]==-1)
			return null;
		if(dp[bs]>0)
			return path[bs];
		fill(bs);
//		System.out.println("done fill");
		LinkedList<Integer> ret=new LinkedList<Integer>();
		for(int i=0;i<N;i++){
			if((bs&(1<<i))!=0)
				continue;
			if(!keys[bs].contains(T[i]))
				continue;
//			System.out.println("i="+i);
			if(find(bs|(1<<i))!=null){
				ret.add(i+1);
				ret.addAll(find(bs|(1<<i)));
				break;
			}
		}
		if(ret.size()==0){
//		System.out.println("not found");
			dp[bs]=-1;
			return null;
		}
		dp[bs]=1;
		path[bs]=ret;
		return ret;
	}
	
	static int N;
	static LinkedList<Integer> keyst;
	static int T[];
	static LinkedList<Integer> K[];
	static int lim;
	static int dp[];
	static LinkedList<Integer> keys[];
	static LinkedList<Integer> path[];
	static void fill(int bs){
		keys[bs]=new LinkedList<Integer>();
		keys[bs].addAll(keyst);
		for(int i=0;i<N;i++){
			if((bs&(1<<i))==0)
				continue;
			keys[bs].addAll(K[i]);
		}
		boolean okay=true;
		for(int i=0;i<N;i++){
			if((bs&(1<<i))==0)
				continue;
			okay&=keys[bs].remove(Integer.valueOf(T[i]));				
		}
		if(!okay)
			dp[bs]=-1;
	}
}
