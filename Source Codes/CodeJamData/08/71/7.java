
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class A {

	static int n;
	static Map<String,Integer> ma;
	static List<String>[] deps;
	static boolean dep[][];
	
	private static void visit(int cn) {
		dep[0][cn]=true;
		for (int i=0; i<n; i++)
			if (cn!=i && dep[cn][i])
				visit(i);
	}
	
	private static int solve(int cur) {
		int ch[] = new int[deps[cur].size()];
		int i=0;
		int nc=0;
		for (String dn : deps[cur]) {
			int j=ma.get(dn);
			ch[i]=solve(j);
			i++;
			nc++;
		}
		Arrays.sort(ch);
		int mc=0;
		int nc2=0;
		for (i=ch.length-1; i>=0; i--) {
			if (i==ch.length-1) {
//				System.out.println(cur+" "+i+" "+ch[i]);
				mc=ch[i];
			}
			else {
				if (ch[i]+nc2>mc) mc+=1;
			}
			nc2++;
		}
		return mc+(mc>nc?0:1);
	}
	
	private static String solve(BufferedReader br) throws Exception {
		n = Integer.parseInt(br.readLine());
		dep = new boolean[n][n];
		deps = new ArrayList[n];
		int max=0;
		String name[] = new String[n];
		ma = new HashMap<String,Integer>();
		for (int i=0; i<n; i++) {
			String s[] = br.readLine().split(" ");
			name[i]=s[0].trim();
			ma.put(name[i],i);
			int m=Integer.parseInt(s[1]);
			deps[i] = new ArrayList<String>();
			for (int j=0; j<m; j++) {
				String dn = s[2+j];
				if (dn.toUpperCase().equals(dn)) {
					deps[i].add(dn);
				}
			}
		}
		
		for (int i=0; i<n; i++) {
			for (String dn : deps[i]) {
//				System.out.print(dn+" ");
				dep[i][ma.get(dn)]=true;
			}
//			System.out.println();
		}
		
//		visit(0);
//		for (int i=0; i<n; i++)
//			if (dep[0][i]) {
//				max = Math.max(max,deps[i].size());
//			}
		
//		System.out.println(solve(1));
//		System.out.println("x");
		return ""+solve(0);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int ncases = Integer.parseInt(br.readLine().trim());
		for (int i=0; i<ncases; i++) {
			System.out.println("Case #"+(i+1)+": "+solve(br));
		}
	}

}
