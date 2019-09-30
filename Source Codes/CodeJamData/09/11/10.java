import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;

public class A {
//	private static boolean[][] yes = new boolean[11914485][10];
//	private static boolean[][] no = new boolean[11914485][10];
	private static short[] yes = new short[11914485];
	private static short[] no = new short[11914485];
	
	private static boolean doit(int x, int base) {
		Set<Integer> set = new HashSet<Integer>();
		set.add(x);
		String num = Integer.toString(x, base);
		while(true) {
			// num => f(num) in decimal
			int fnum = 0;
			for(int i=0;i<num.length();++i) {
				fnum += (num.charAt(i)-'0')*(num.charAt(i)-'0');
			}
			if(set.contains(fnum) || (no[fnum]&(1<<base))>0) {
				for(int nn : set)
					no[nn] |= (1<<base);
				return false;
			}
			if(fnum == 1 || (yes[fnum]&(1<<base))>0) {
				for(int nn : set)
					yes[nn] |= (1<<base);
				return true;
			}
			set.add(fnum);
			num = Integer.toString(fnum, base);
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int e = 0, T;
		String tmp = sc.nextLine();
		T = Integer.parseInt(tmp);
		//11814485
		int[] mini = new int[2048];
		for(int x=2;x<=11814585;x++) {
			int pos = 0;
			for(int b=2;b<=10;b++) {
				if(doit(x, b))
					pos += (1<<b);
			}
			if(mini[pos] == 0) mini[pos] = x;
			if(x%500000==0)
				System.out.println(x*100/11814585.0);
		}
		System.out.format("%d vs %d\n",mini[124], mini[1148]);
		for(int i=0;i<2048;i++) {
			if(mini[i]==0)continue;
			for(int j=0;j<i;j++) {
				if((i&j)==j && (mini[j]==0 || mini[j]>mini[i]))
					mini[j] = mini[i];
			}
		}
		System.out.format("%d vs %d\n",mini[124], mini[1148]);
		System.out.println("pre done\n");
		for(int i=0;i<T;i++) {
			String line = sc.nextLine();
			LinkedList<Integer> bases = new LinkedList<Integer>();
			Scanner subsc = new Scanner(line);
			while(subsc.hasNext()) {
				bases.addFirst(subsc.nextInt());
			}			
			int ans = 0;
			for(int base : bases) {
				ans += 1<<base;
			}
			
//			for(int x = 2;; x++) {
//				boolean failed = false;
//				for(int base : bases) {
//					if(!doit(x, base)) {
//						failed = true;
//						break;
//					}
//				}
//				if(!failed) {
//					ans = x;
//					break;
//				}
//			}
						
			System.out.format("Case #%d: %d\n",++e, mini[ans]);
		}
	}
}
