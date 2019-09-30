import java.io.*;
import java.util.*;
public class cc{
	long[]vv;
	int cauta(long va,int li,int ls){
		if(li==ls) return li;
		int mid = (li+ls)/2;
		//System.err.println(va+" "+vv[mid]);
		if(vv[mid]==va)return mid;
		else  if(vv[mid]>va) return cauta(va,li,mid-1);
		else return cauta(va,mid+1,ls);
		//return -1;
	}
	cc(){
		try{
			File f = new File("C-large.in");
			BufferedReader input =  new BufferedReader(new FileReader(f));
			BufferedWriter out = new BufferedWriter(new FileWriter("large.out"));
			int nrtests = Integer.parseInt(input.readLine());
			for(int nrt=0;nrt<nrtests;nrt++){
				String[]spl=input.readLine().split(" ");
				long mod = 1000000007;
				int n = Integer.parseInt(spl[0]);
				int m = Integer.parseInt(spl[1]);
				long x = Long.parseLong(spl[2]);
				long y = Long.parseLong(spl[3]);
				long z = Long.parseLong(spl[4]);
				long[] a = new long[m];
				for(int i=0;i<m;i++) a[i] = Long.parseLong(input.readLine());
				long[]v =new long[n];
				vv=new long[n];
				for(int i=0;i<n;i++){
					v[i] = a[i%m];
					vv[i] = a[i%m];
					a[i%m] = (x*a[i%m]+y*(i+1))%z;
				}
				Arrays.sort(vv);
				long rez=0;
				long[]nr = new long[n];
				long[]aib = new long[2*n+2];
				Arrays.fill(aib,0);
				for(int i=0;i<n;i++)
					{
						long shit=1;
						int poz = cauta(v[i],0,n-1);
						//if(poz==-1)System.err.println("???"+" "+nrt+" "+v[i]+" "+n);
						int aux = poz;
						while(aux>0){ shit=(shit+aib[aux])%mod; aux=aux&(aux-1);}
						aux = poz+1;
						while(aux<2*n+2){ aib[aux]=(shit+aib[aux])%mod; aux=(aux|(aux-1))+1; }
						rez=(rez+shit)%mod;
					}
				System.err.println(nrt);
				out.write("Case #"+(nrt+1)+": "+rez+"\n");
			}
			out.close();
		}catch(IOException e){}
	}
	public static void main(String[]args){
		new cc();
	}

}