import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.TreeMap;

public class Main {

    private int n;
    private TreeMap<Integer,Integer> a;
    
    public static void main(String[] args) {
	Main m = new Main();
	m.solve();
    }

    private void set() {
	try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
	    n = Integer.parseInt(br.readLine());
	    a = new TreeMap<>();
	    for (String str : br.readLine().split(" ")) {
		int ai = Integer.parseInt(str);
		int num = a.getOrDefault(ai,0) + 1;
		a.put(ai,num);
	    }
	} catch(IOException e) {
	    e.printStackTrace();
	}
    }

    private void solve() {
	set();
	int pair = 0;
	while (!a.isEmpty()) {
	    int ai = a.lastKey();
	    int complement = 2*Integer.highestOneBit(ai) - ai;
	    if (ai == complement) {
		int num = a.get(ai);
		pair += num/2;
		a.remove(ai);
		continue;
	    }
	    if (a.containsKey(complement)) {
		int numA = a.get(ai);
		int numC = a.get(complement);
		if (numA < numC) {
		    pair += numA;
		    a.remove(ai);
		    a.put(complement,numC-numA);
		} else {
		    pair += numC;
		    a.remove(ai);
		    a.remove(complement);
		}
		continue;
	    }
	    a.remove(ai);
	}
	System.out.println(pair);
    }
}