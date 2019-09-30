import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.TreeMap;

public class Main {

    private int n;
    private int[] a;
    private TreeMap<Integer,Integer> s;
    
    public static void main(String[] args) {
	Main m = new Main();
	m.solve();
    }

    private void set() {
	try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
	    n = Integer.parseInt(br.readLine());
	    a = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
	    s = new TreeMap<>();
	} catch(IOException e) {
	    e.printStackTrace();
	}
    }

    private void solve() {
	set();
	int ng = 0;
	int ok = n;
	while (ok-ng > 1) {
	    int k = (ng+ok)/2;
	    if (isPossible(k)) {
		ok = k;
	    } else {
		ng = k;
	    }
	}
	System.out.println(ok);
    }

    private boolean isPossible(int k) {
	s.clear();
	int current = 0;
	for (int ai : a) {
	    if (ai <= current) {
		if (k == 1) return false;
		while (!s.isEmpty() && s.lastKey() >= ai) s.pollLastEntry();
		int p = ai-1;
		while (true) {
		    if (p < 0) return false;
		    int sp = s.getOrDefault(p,0) + 1;
		    s.put(p,sp);
		    if (sp == k) {
			s.remove(p);
			p--;
		    } else {
			break;
		    }
		}
	    }
	    current = ai;
	}
	return true;
    }
}