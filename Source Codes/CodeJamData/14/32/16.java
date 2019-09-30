import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;



import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  


public class B {
	
	Scanner scan;
	public B(Scanner s) {
		this.scan = s;
	}
	String[]A;
	long brut(char last, boolean[]U,boolean[]L) {
		long r =0;
		boolean  all=true;
		for(int i=0;i<A.length;i++){
			
			if(U[i])continue;
			all=false;
			boolean[]nl = L.clone();
			char lc = '#';
			for(char c:A[i].toCharArray()){
				if(nl[c]) {
					if(lc!=c && !(c==last && c==A[i].charAt(0)))return 0;
				}
				nl[c]=true;
			}
			U[i]=true;
			r += brut(A[i].charAt(A[i].length()-1),U, nl);
			U[i]=false;
		}
		if(all)return 1;
		return r%1000000007;
	}
	
	public String solve() {
		int n = scan.nextInt();
		A = new String[n];
		for(int i=0;i<n;i++){
			A[i]= "";String s =scan.next();
			for(int j=0;j<s.length();j++) {
				if(A[i].length()==0 || A[i].charAt(A[i].length()-1)!=s.charAt(j))A[i]+=s.charAt(j);
			}
			System.out.print(A[i] +" ");
		}
	//	System.out.println();
		/*
		long res = brut('#', new boolean[n], new boolean[256]);
		return ""+res;
	*/
		boolean[]EQ = new boolean[n];
		for(int sn=0;sn<n;sn++){
			String s = A[sn];
			int d=0;
			boolean[] v = new boolean[256];
			for(int i=0;i<s.length();i++){
				if(v[s.charAt(i)] && s.charAt(i-1)!=s.charAt(i))return "0";
				if(!v[s.charAt(i)]) {
					d++;
					v[s.charAt(i)]=true;
				}
				if(i>0 && s.charAt(i)!=s.charAt(0) && i+1<s.length() && s.charAt(i) !=s.charAt(s.length()-1)){
					for(int j=0;j<n;j++){
						if(j==sn)continue;
						for(char c:A[j].toCharArray()) {
							if(c==s.charAt(i))return "0";
						}
					}
				}
			}
			EQ[sn]=d==1;
		}
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){
			if(i==j)continue;
			if(EQ[i]||EQ[j])continue;
			if(A[i].charAt(0)==A[j].charAt(0))return "0";
			if(A[i].charAt(A[i].length()-1)==A[j].charAt(A[j].length()-1))return "0";
		}
		boolean[][]M = new boolean[n][n];
		int[]inc = new int[n];
		int[]out = new int[n];
		int parts =0;
		for(int i=0;i<n;i++){
			if(EQ[i])continue;
			parts++;
			for(int j=0;j<n;j++){
				if(EQ[j]||i==j)continue;
				if(A[i].charAt(A[i].length()-1)==A[j].charAt(0)){
					M[i][j]=true;
					inc[j]++;
					out[i]++;
				}
			}
		}
		for(int i=0;i<n;i++)if(inc[i]>1||out[i]>1)return "0";
		int ch=0; 
		boolean cover[]=new boolean[n];
		ArrayList<String> seg = new ArrayList<>();
		for(int i=0;i<n;i++){
			if(EQ[i])continue;
			if(inc[i]==0 && out[i]==0){
				seg.add(A[i].charAt(0)+""+A[i].charAt(A[i].length()-1));
				cover[i]=true;
			}
			if(inc[i]>0 || out[i]==0)continue;
			String s =""+A[i].charAt(0);
			int p =i;
			cover[p]=true;
			while(out[p]>0){
			
				for(int j=0;j<n;j++)
					if(M[p][j]){
						p=j;
						cover[p]=true;
					}
			}
			s+=A[p].charAt(A[p].length()-1);
			seg.add(s);
		}
		for(int i=0;i<n;i++)if(!EQ[i]&&!cover[i])return "0";
		long res = 1;
		int free =0;
		long mod =  1000000007;
		for(char c = 'a';c<='z';c++){
			int count=0;boolean att = false;
			for(int i=0;i<n;i++){
				if(EQ[i]){
					if(A[i].charAt(0)==c)count++;
				}
			}
			if(count==0)continue;
			for(int i=0;i<A.length;i++){
				String s = A[i];
				if(EQ[i])continue;
				if(s.charAt(0)==c || s.charAt(s.length()-1)==c)att=true;
			}
			if(!att && count >0)free++;
			for(int i=1;i<=count;i++)res = (res*i)%mod;
		}
		for(int i=1;i<=seg.size()+free;i++)res = (res*i)%mod;
		return ""+res;
		
		
	}
	int intLine(){
		return parseInt(scan.nextLine());
	}
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		String cn = B.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt4.in";
		String largeName = cn+"-large.in";
		String name = largeName;
		String outName = name.substring(0, name.indexOf('.'))+".out";
		InputStream in = new BufferedInputStream(new FileInputStream(name));
		PrintStream out = new PrintStream(new File(outName));
		//PrintStream out = System.out;
		Scanner scan = new Scanner(in);
		
		int N = parseInt(scan.nextLine());
		for(int c=1;c<=N;c++) {
			
			String res = new B(scan).solve();
			out.printf("Case #%d: %s\n",c, res);
			System.err.println(c + " done");
		}
		
		System.err.println("All done");
		
	}

}


