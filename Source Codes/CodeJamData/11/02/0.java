import java.util.*;

import static java.lang.Math.*;

public class B {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz = 1; zz <= T;zz++){
			int C = in.nextInt();
			String[] combine = new String[C];
			for(int i = 0; i < C;i++)
				combine[i] = in.next();
			int D = in.nextInt();
			String[] oppose = new String[D];
			for(int i = 0; i < D;i++)
				oppose[i] = in.next();
			int N = in.nextInt();
			String S = in.next();

			ArrayList<Character> list = new ArrayList<Character>();
			for(int i = 0; i < N;i++){
				char c = S.charAt(i);
				list.add(c);
				boolean removed = false;
				if(list.size() >= 2){
					char l1 = list.get(list.size()-2);
					char l2 = list.get(list.size()-1);
					for(String comb: combine){
						char a = comb.charAt(0);
						char b = comb.charAt(1);
						
						if((a == l1 && b == l2) || (a == l2 && b == l1)){
							list.remove(list.size()-1);
							list.remove(list.size()-1);
							list.add(comb.charAt(2));
							removed = true;
							break;
						}
					}
				}
				if(!removed){
					done:
					for(int k = 0; k < list.size(); k++){
						for(int j = 0; j < list.size(); j++){
							if(k == j)
								continue;
							for(String opp : oppose){
								if(list.get(k) == opp.charAt(0) && list.get(j) == opp.charAt(1)){
									list = new ArrayList<Character>();
									break done;
								}
							}
						}
					}
				}
			}

			String ans = list.toString();
			System.out.format("Case #%d: %s\n", zz, ans);
		}
	}
}
