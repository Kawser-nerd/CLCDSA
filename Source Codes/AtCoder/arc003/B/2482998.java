import com.sun.org.apache.xalan.internal.xsltc.util.IntegerArray;

import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static boolean debug = false;
	static boolean debug2 = false;

	public static void main(String[] args) throws java.io.IOException {
		debug = 1 <= args.length;
		debug2 = 2 <= args.length;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));


		reverse[] items = new reverse[Integer.parseInt(in.readLine())];
		for (int i = 0; i < items.length; ++i) {
			items[i] = new reverse(in.readLine());
		}
		Arrays.sort(items);

		for (int i = 0; i < items.length; ++i) {
			System.out.println(items[i]);
		}
	}

	static class reverse implements Comparable<reverse> {
		private String orig;
		private String str;

		public reverse(String s) {
			orig = s;
			StringBuffer sb = new StringBuffer(s);
			str = sb.reverse().toString();
		}

		@Override
		public int compareTo(reverse o) {
			return str.compareTo(o.str);
		}

		@Override
		public String toString() {
			return orig;
		}
	}
} ./Main.java:1: warning: IntegerArray is internal proprietary API and may be removed in a future release
import com.sun.org.apache.xalan.internal.xsltc.util.IntegerArray;
                                                   ^
1 warning