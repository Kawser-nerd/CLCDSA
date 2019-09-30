package gcj2009.round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.ObjectInputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;

public class BribeThePrisoners {
	
	public static final String path = "google/gcj2009/round1c/resources";
	public static final String inFile = "C-large.in";
	public static final String outFile = "C-large.out";
	public static final String objFile = "C.obj";
	
	
	static HashSet<Integer> release;
	static HashMap<Integer, Integer> map;
	
	private static int idx(int i1, int i2) {
		return i1*10001+i2;
	}
	
	private static int rec(int l, int r) {
		if (l>=r) return 0;
		int idx = idx(l, r);
		if (map.containsKey(idx)) return map.get(idx);
		
		int min = 100000000;
		for (int i=l; i<=r; i++) {
			if (release.contains(i+1)) {
				//System.out.println("release contains:"+i);
				int s = rec(l, i-1) + rec(i+1, r);
				if (s<min) min = s;
			}
		}
		int res = min + r - l;
		if (res >= 100000000) res = 0;
		map.put(idx, res);
		//System.out.println(l+" "+r+" "+res);
		return res;
	}
	
	public static String solve(BufferedReader in) throws Exception {
		String[] ss = in.readLine().trim().split(" ");
		int n = Integer.parseInt(ss[0]);
		int q = Integer.parseInt(ss[1]);
		release = new HashSet<Integer>();
		ss = in.readLine().trim().split(" ");
		for (int i=0; i<q; i++) {
			release.add(Integer.parseInt(ss[i]));
		}
		
		map = new HashMap<Integer, Integer>();
		return Integer.toString(rec(0, n-1));
	}
	
	
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader in = new BufferedReader(new FileReader(path + "/" + inFile));
		BufferedWriter out = new BufferedWriter(new FileWriter(path + "/" + outFile));
		
//		ObjectInputStream obj = new ObjectInputStream(new FileInputStream(path + "/" + objFile));		
//		res = (int[])obj.readObject();
		
		
		
		int ncases = Integer.parseInt(in.readLine().trim());
		for (int i=0; i<ncases; i++) {
			String res = solve(in);
			System.out.println("Handled case: "+(i+1));
			out.write("Case #"+(i+1)+": "+res+"\n");			
		}
		in.close();
		out.close();
	}
}
