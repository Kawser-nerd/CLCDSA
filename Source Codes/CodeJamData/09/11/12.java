import java.io.*;
import java.util.*;



public class AAA {
	
	boolean getsum1(int n, int k){
		TreeSet<Integer> y = new TreeSet<Integer>();
		while (true){
			if (y.contains(n)) return false;
			y.add(n);
			int res = 0;
			while (n != 0){
				res += (n % k) * (n % k);
				n /= k;
			}
			n = res;
			if (n == 1) return true;
		}
	}
	
	TreeMap<Integer, Integer> result = new TreeMap<Integer, Integer>();

	void solve() throws IOException {
		Scanner in = new Scanner(new FileInputStream("input.txt"));
		PrintWriter out = new PrintWriter(new FileOutputStream("output.txt"));
		String s;
		int n = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= n; ++t){
			s = in.nextLine();
			if (s == null) break;
			ArrayList<Integer> a = new ArrayList<Integer>();
			Scanner in2 = new Scanner(s);
			while (in2.hasNextInt())
				a.add(in2.nextInt());
			int mask = 0;
			for (int i = 0; i < a.size(); ++i)
				mask += 1<<a.get(i);
			if (a.size() == 9) result.put(mask, 11814485);
			int tr = 2;
			if (result.containsKey(mask)){
				tr = result.get(mask);
			}
			else{
				while (true){
					boolean good = true;
					for (int i = a.size() - 1; i >= 0; --i)
						if (!getsum1(tr, a.get(i))){
							good = false;
							break;
						}
					if (good) break;
					tr++;
				}
				result.put(mask, tr);
			}
			out.println("Case #" + t + ": " + tr);
			out.flush();
		}
		out.close();
	}
	public static void main(String[] args) throws IOException {
		AAA a = new AAA();
		a.solve();
	}

}
