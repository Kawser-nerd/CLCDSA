import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * http://abc031.contest.atcoder.jp/tasks/abc031_d
 */
public class Main {

	static int K;
	static int N;
	static String[] v;
	static String[] w;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		K = sc.nextInt();
		N = sc.nextInt();
		v = new String[N];
		w = new String[N];
		for(int i=0; i<N; i++){
			v[i] = sc.next();
			w[i] = sc.next();
		}
		sc.close();
		
		String[] ans = dfs(new ArrayList<Integer>());
		
		for(int i=1; i<=K; i++){
			System.out.println(ans[i]);
		}

	}

	static String[] dfs(List<Integer> list) {
		if(list.size()==K){
			String[] ans = new String[K+1];
			for(int i=0; i<N; i++){
				int current = 0;
				for(int d=0; d<v[i].length(); d++){
					int n = v[i].charAt(d) - '0';
					int size = list.get(n-1);
					if(w[i].length() < current+size) return null;
					String s = w[i].substring(current, current+size);
					if(ans[n]==null){
						ans[n]=s;
					}else if(!ans[n].equals(s)){
						return null;
					}
					current += size;
				}
				if(w[i].length() != current) return null;
			}
			return ans;
		}
		
		for(int i=1; i<=3; i++){
			List<Integer> newList = new ArrayList<>();
			for(int l:list) newList.add(l);
			newList.add(i);
			String[] result = dfs(newList);
			if(result != null ) return result;
		}
		return null;
	}

}