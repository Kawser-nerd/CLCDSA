package gcj2009.round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.ObjectInputStream;
import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;

public class AlienLanguage {
	
	public static final String path = "google/gcj2009/round1c/resources";
	public static final String inFile = "A-large.in";
	public static final String outFile = "A-large.out";
	public static final String objFile = "A.obj";
	
	static int idx(char c) {
		if (Character.isDigit(c)) return c-'0';
		else return c - 'a' + 10;
	}
	
	public static String solve(BufferedReader in) throws Exception {
		String s = in.readLine().trim();
		int[] arr = new int[37];
		Arrays.fill(arr, -1);
		int count = 2;
		arr[idx(s.charAt(0))] = 1;
		boolean nullFree = true;
		for (char c: s.toCharArray()) {
			if (arr[idx(c)] == -1) {
				if (nullFree) {
					arr[idx(c)] = 0;
					nullFree = false;
				} else {
					arr[idx(c)] = count++;
				}
			}
		}
		
		long factor = 1;
		long res = 0;
		for (int i=s.length()-1; i>=0; i--) {
			res += arr[idx(s.charAt(i))]*factor;
			factor*=count;
		}
		
		return Long.toString(res);
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
