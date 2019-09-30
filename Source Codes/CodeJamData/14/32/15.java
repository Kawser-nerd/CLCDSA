import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils.Collections;


public class ReorderingTrainCars {

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
			int N=Integer.parseInt(br.readLine());
			String car[]=new String[N];
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++){
				String str=st.nextToken();
				for(int j=0;j<str.length()-1;j++){
					if(str.charAt(j)==str.charAt(j+1)){
						str=str.substring(0, j)+str.substring(j+1);
						j--;
					}
				}
				car[i]=str;
			}
			System.out.println(Arrays.toString(car));
			

			
			boolean okay=true;
			//check if any single car makes it impossible
			for(int i=0;i<N;i++)
				okay&=check(car[i]);
			//check pairwise if there is a valid
			for(int i=0;i<N;i++){
				for(int j=i+1;j<N;j++){
					okay&=check(car[i]+car[j])||check(car[j]+car[i]);
				}
			}
			//check if cyclic... somehow
			
			
			
			
			
			//count and remove all single letter cars
			int scar[]=new int[26];
			int sctr=0;
			for(int i=0;i<N;i++){
				if(car[i].length()==1){
					scar[car[i].charAt(0)-'a']++;
					sctr++;
				}
			}
			int stypes=0;
			for(int i=0;i<26;i++)
				if(scar[i]>0)
					stypes++;
			String car2[]=new String[N-sctr];
			int cur=0;
			for(int i=0;i<N;i++){
				if(car[i].length()>1)
					car2[cur++]=""+car[i];
			}
			car=car2;
//			System.out.println(Arrays.toString(car));
			N-=sctr;			
			
			//connect what must be connected
			LinkedList<String> ll=new LinkedList<String>();
			for(int i=0;i<N;i++)
				ll.add(car[i]);
			for(int i=0;i<26;i++){
				LinkedList<String> ll2=new LinkedList<String>();
				String bef=null, af=null;
				for(String str:ll){
					if(str.charAt(0)=='a'+i)
						af=str;
					else if(str.charAt(str.length()-1)=='a'+i)
						bef=str;
					else
						ll2.add(str);
				}				
				if(af!=null){
					if(bef!=null)
						bef=bef+af;
					else
						ll2.add(af);
				}
				if(bef!=null)
					ll2.add(bef);
				ll=ll2;
				

				if((bef!=null||af!=null)&&scar[i]>0)
					stypes--;
			}
			car2=new String[ll.size()];
			cur=0;
			for(String str:ll){
				car2[cur++]=str;
			}
			car=car2;
			System.out.println(Arrays.toString(car));
			

			//check if any single car makes it impossible (made cycle)
			for(String str:ll)
				okay&=check(str);
				
				
			long ans=(okay)?fact(ll.size()+stypes):0;
			for(int i=0;i<26;i++)
				ans=(ans*fact(scar[i]))%mod;
			
			System.out.println(ll.size()+" "+stypes);
			
//			if(!okay)
			System.out.println(cn+": "+ans);
			bw.append("Case #"+cn+": ");
			bw.append(ans+"\n");
		}
		bw.flush();

	}
	static int mod=1000000007;
	static boolean check(String st){
		boolean used[]=new boolean[26];
		int cur=-1;
		int len=st.length();
		boolean okay=true;
		for(int i=0;i<len;i++){
			int c=st.charAt(i)-'a';
			if(c!=cur){
				if(used[c])
					okay=false;
				used[c]=true;
				cur=c;
			}
		}
		return okay;
	}
	static long fact(long n){
		if(n==0||n==1)
			return 1;
		return (n*fact(n-1))%mod;
	}
}
