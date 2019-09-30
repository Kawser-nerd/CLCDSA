import java.util.*;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.Deque;


public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        boolean[] covered = new boolean[n+1];
        Interval[] abs = new Interval[m];
        
        for (int i = 0; i < m; i++) {
            String[] s = br.readLine().split(" ");
            int a = Integer.parseInt(s[0]);
            int b = Integer.parseInt(s[1]);
            Interval intr = new Interval(a, b);
            abs[i] = intr;
        }
        
        Arrays.sort(abs, new IntervalComparator());
        
        int count = 0;
        for (Interval ab : abs) {
            if (!covered[ab.a]) {
                count++;
                for (int i = 0; i < ab.b; i++) {
                    covered[i] = true;
                }
            }
        }
        
        System.out.println(count);
    }
}

class Interval {
    int a;
    int b;
    public Interval(int a, int b) {
        this.a = a;
        this.b = b;
    }
}

class IntervalComparator implements Comparator<Interval>{
	public int compare(Interval intr1, Interval intr2) {
		return intr1.b - intr2.b;
	}
}