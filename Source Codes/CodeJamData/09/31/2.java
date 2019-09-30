import java.util.*;
import java.math.*;
class Main{
	public static void main(String [] argv){
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for(int t = 1; t <= tests; t++){
			char [] cs = sc.next().toCharArray();
			TreeSet<Integer> ts = new TreeSet<Integer>();
			for(char c: cs){
				ts.add((int)c);
			}
			int base = ts.size();
			if(base == 1){
				base++;
			}
			TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
			boolean [] use = new boolean[256];
			map.put((int)cs[0], 1);
			use[1] = true;
			for(int i = 1; i < cs.length; i++){
				if(map.get((int)cs[i]) == null){
					boolean flg = false;
					for(int j = 0; j < 256 && !flg; j++){
						if(!use[j]){
							flg = true;
							use[j] = true;
							map.put((int)cs[i], j);
						}
					}
				}
			}
			System.err.println("base:" + base);
			for(int i = 0; i < cs.length; i++){
				System.err.print(map.get((int)cs[i]));
			}
			//System.out.println();
			BigInteger bibase = new BigInteger("" + base);
			BigInteger now = new BigInteger("" + map.get((int)cs[0]));
			for(int i = 1; i < cs.length; i++){
				now = now.multiply(bibase).add(new BigInteger("" + map.get((int)cs[i])));
			}

			System.out.printf("Case #%d: %d\n", t, now);
		}
	}

}
