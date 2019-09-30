import java.io.*;
import java.util.*;
public class a{
	a(){
		try{
			File f = new File("A-large.in");
			BufferedReader input =  new BufferedReader(new FileReader(f));
			BufferedWriter out = new BufferedWriter(new FileWriter("large.out"));
			int nrtests = Integer.parseInt(input.readLine());
			for(int nrt=0;nrt<nrtests;nrt++){
				String[]spl=input.readLine().split(" ");
				long p = Integer.parseInt(spl[0]);
				long k = Integer.parseInt(spl[1]);
				long l = Integer.parseInt(spl[2]);
				spl=input.readLine().split(" ");
				int n = spl.length;
				long[]v= new long[n];
				for(int i=0;i<n;i++) v[i] = Long.parseLong(spl[i]);
				Arrays.sort(v);
				String ans = "Impossible";
				if( p*k>=l ){
					long rez=0;
					for(long pas=0,poz=n-1; pas<p; pas++)
						for(long j=0;j<k; j++,poz--)
							if(poz>=0) rez+=(long)(pas+1)*(long)v[(int)poz];
					ans=""+rez;
				}
				out.write("Case #"+(nrt+1)+": "+ans+"\n");
			}
			out.close();
		}catch(IOException e){}
	}
	public static void main(String[]args){
		new a();
	}

}