package r1;
import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class ProgramB {
	static final boolean _PRACTICE = !true;
	static final boolean _SAMPLE = !true;
	static final boolean _SMALL = !true;
	static final String _PROBLEM = "B";

	void debug(Object... os) {
//		System.err.println(deepToString(os));
	}

	void run() {
//		String[] ss = new String[10000];
//		Random rand = new Random();
//		for(int i=0;i<10000;i++) {
//			ss[i]="";
//			for(int j=0;j<10;j++) {
//				ss[i] += (char)(rand.nextInt(26)+'a');
//			}
//		}
//		String l="";
//		for(int i=0;i<26;i++)l+=(char)('a'+i);
//		calc(ss,new String[] {l});
//		System.out.println("end");
		
		
		Scanner sc = new Scanner(System.in);
		int oo = sc.nextInt();
		for (int o = 1; o <= oo; o++) {
			System.err.println(o);
			System.out.printf("Case #%d: ", o);
			
			ArrayList<String>[] lists = new ArrayList[11];
			for(int i=0;i<11;i++)lists[i] = new ArrayList<String>();
			int N=sc.nextInt(),M=sc.nextInt();
			HashMap<String,Integer> s2i = new HashMap<String,Integer>();
			for(int i=0;i<N;i++) {
				String s = sc.next();
				s2i.put(s,i);
				lists[s.length()].add(s);
			}
			String[] L=new String[M];
			for(int i=0;i<M;i++)L[i] = sc.next();
			int[] max=new int[M];
			for(int i=0;i<M;i++)max[i]=-1;
			String[] strs=new String[M];
			for(int i=0;i<11;i++) {
				String[] D = lists[i].toArray(new String[0]);
				if(D.length==0)continue;
				calc(D,L);
				for(int j=0;j<M;j++) {
					if(res[j]>max[j] || res[j]==max[j] && s2i.get(strs[j]) > s2i.get(ss[j])) {
						max[j] = res[j];
						strs[j] = ss[j];
					}
				}
			}
			for(int i=0;i<M;i++) {
				if(i>0)System.out.print(" ");
				System.out.print(strs[i]);
			}
			System.out.println();
		}
	}
	
	int[] res;
	String[] ss;
	int N,M;
	int[] numPat;
	int[][] pat;
	void calc(String[] D,String[] L) {
		for(String s:D)assert s.length() == D[0].length();
		
		int len = D[0].length();
		N = D.length;
		M = L.length;
		res = new int[M];
		ss = new String[M];
		
		numPat = new int[26];
		pat = new int[N][26];
		for(int i=0;i<26;i++) {
			TreeSet<Integer> patSet = new TreeSet<Integer>();
			for(int j=0;j<N;j++) {
				int msk = 0;
				for(int k=0;k<len;k++)if((D[j].charAt(k)-'a')==i) {
					msk |= 1<<k;
				}
				patSet.add(msk);
			}
			Integer[] pats = patSet.toArray(new Integer[0]);
			numPat[i] = pats.length;
			for(int j=0;j<N;j++) {
				int msk = 0;
				for(int k=0;k<len;k++)if((D[j].charAt(k)-'a')==i) {
					msk |= 1<<k;
				}
				pat[j][i] = binarySearch(pats,(Integer)msk);
			}
		}
		for(int i=0;i<M;i++) {
			int[] is = func(D,L[i]);// max,id
			res[i] = is[0];
			ss[i] = D[is[1]];
		}
	}
	int[] func(String[] D,String L) {
		ArrayList<Integer> is = new ArrayList<Integer>();
		int N = D.length;
		for(int i=0;i<N;i++)is.add(i);
		rs = new int[2];
		rs[0] = -1;
		dfs(D,is,0,L,0);
		return rs;
	}
	int[] rs;
	private void dfs(String[] D,ArrayList<Integer> is,int id,String l,int pen){
		debug(D);
		debug(is);
		debug("ch",l.charAt(id));
		debug("pen",pen);
		int ch = l.charAt(id)-'a';
		assert is.size()>0;
		if(is.size()==1) {
			int ni = is.get(0);
			if(rs[0] < pen || rs[0] == pen && rs[1] > ni) {
				rs[0] = pen;
				rs[1] = ni;
			}
			return;
		}
		ArrayList<Integer>[] nlist = new ArrayList[numPat[ch]];
		
		int numEx = 0;
		for(int j=0;j<is.size();j++) {
			int ni = is.get(j);
			int p = pat[ni][ch];
			if(nlist[p]==null) {
				nlist[p] = new ArrayList<Integer>();
				numEx++;
			}
				nlist[p].add(ni);
		}
		assert numEx>0;
		if(numEx==1) {
			debug("one");
			for(int i=0;i<nlist.length;i++) {
				if(nlist[i]!=null) {
					dfs(D,nlist[i],id+1,l,pen);
					return;
				}
			}
			assert false;
		}else {
			debug("else");
			for(int i=0;i<nlist.length;i++) {
				if(nlist[i]!=null) {
					boolean con = D[nlist[i].get(0)].contains(""+((char)(ch+'a')));
					if(con)dfs(D,nlist[i],id+1,l,pen);
					else dfs(D,nlist[i],id+1,l,pen+1);
				}
			}
		}
	}

	public static void main(String... args) throws IOException {
		if (!_SAMPLE) {
			if (_SMALL) {
				int i = 0;
				while (new File(_SMALLNAME(i) + ".in").exists())
					i++;
				i--;
				boolean test = false;
				if (new File(_SMALLNAME(i) + ".out").exists()) {
					System.err.println("overwrite?(y/n)");
					char c = (char) System.in.read();
					test = c != 'y';
				}
				if (test) {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_PROBLEM + "-small-test.out"));
					new ProgramB().run();
					FileReader f1 = new FileReader(_PROBLEM + "-small-test.out");
					FileReader f2 = new FileReader(_SMALLNAME(i) + ".out");
					BufferedReader br1 = new BufferedReader(f1);
					BufferedReader br2 = new BufferedReader(f2);
					for (int j = 1;; j++) {
						String s1 = br1.readLine();
						String s2 = br2.readLine();
						if (s1 == null && s2 == null) {
							System.err.println("OK!");
							break;
						}
						if (s1 == null || s2 == null || !s1.equals(s2)) {
							System.err.println("failed at line " + j);
							System.err.println("expected " + s2);
							System.err.println("but " + s1);
							break;
						}
					}
				} else {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_SMALLNAME(i) + ".out"));
					new ProgramB().run();
				}
			} else {
				System.setIn(new FileInputStream(_LARGENAME() + ".in"));
				System.setOut(new PrintStream(_LARGENAME() + ".out"));
				new ProgramB().run();
			}
		} else
			new ProgramB().run();
	}

	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}

	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small" + (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}