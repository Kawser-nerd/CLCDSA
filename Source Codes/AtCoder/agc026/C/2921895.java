import java.util.*;
class Pair<V,K>{
	V first;
	K second;
	public Pair() {first = null;second = null;}
	public Pair(V f,K s){
		first = f;
		second = s;
	}
	public boolean equals(Object o) {
        if(!(o instanceof Pair))
        {
            return false;
        }
        Pair<V,K> pn = (Pair<V,K>)o;
        return pn.first.equals(first) && pn.second.equals(second);
	}
	public int hashCode() {
		return first.hashCode() + second.hashCode();
	}
}
public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long ans = 0;
		int n = in.nextInt();
		String s = in.next();
		String aa = null,bb = null;
		Map<Pair<String,String>,Integer> map = new HashMap();
		for(int i = 0;i < 1 << n;i ++) {
			StringBuilder a = new StringBuilder();
			StringBuilder b = new StringBuilder();
			for(int j = 0;j < n;j ++) {
				if((i >> j) % 2 == 1)a.append(s.charAt(j));
				else b.append(s.charAt(j));
			}
			aa = a.toString();
			bb = b.toString();
			if(map.containsKey(new Pair(aa,bb)))map.put(new Pair(aa,bb),map.get(new Pair(aa,bb)) + 1);
			else map.put(new Pair(aa,bb),1);
		}
		for(int i = 0;i < 1 << n;i ++) {
			StringBuilder a = new StringBuilder();
			StringBuilder b = new StringBuilder();
			for(int j = 0;j < n;j ++) {
				if((i >> j) % 2 == 1)a.append(s.charAt(n * 2 - 1 - j));
				else b.append(s.charAt(n * 2 - 1 - j));
			}
			aa = a.toString();
			bb = b.toString();
			if(map.containsKey(new Pair(aa,bb)))ans += map.get(new Pair(aa,bb));
		}
		System.out.println(ans);
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.