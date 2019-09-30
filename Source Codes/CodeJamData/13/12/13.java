import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.TreeMap;

public class R1B {
public static void main(String[] args) {
		String prblm="B"; boolean fl=true;
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
				int E=Integer.parseInt(tok[0]);
				int R=Integer.parseInt(tok[1]);
				int N=Integer.parseInt(tok[2]);
				s=fr.readLine();
				tok=s.split(" ");
				int[] en=new int[N+1];
				int[] en2=new int[N+1];
				Arrays.fill(en, -1);
				Arrays.fill(en2, -1);
				en2[0]=E;
				en[N]=0;
				TreeMap<Integer,ArrayList<Integer>> tr=new TreeMap<Integer,ArrayList<Integer>>();
				for (int j = 0; j < N; j++) {
					int v=Integer.parseInt(tok[j]);
					if (tr.containsKey(v)){
						ArrayList<Integer> ar=tr.get(v);
						ar.add(j);
					}
					else {
						ArrayList<Integer> ar=new ArrayList<Integer>();
						ar.add(j);
						tr.put(v,ar);
					}
				}
				int tt=(int)Math.ceil(((double)E)/R);
				long val=0;
				for (int v: tr.descendingKeySet()) {
					ArrayList<Integer> ar=tr.get(v);
					for (int j : ar) {
						int pre=E;
						for (int k=j; k>=0 && j-k<tt;k--){ 
							if (en2[k]!=-1) {
								pre=Math.min(E,en2[k]+R*(j-k+1));
								break;
							}
						}
						int pos=0;
						for (int k=j+1; k<=N && k-j<=tt;k++){ 
							if (en[k]!=-1) {
								pos=Math.max(0,en[k]-R*(k-j));
								break;
							}
						}
						en[j]=pre;
						en2[j+1]=pos;
						val+=((long)v)*(pre-pos);
					}
				}
				System.out.println(val);
				fw.write("Case #"+i+": "+ val  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}