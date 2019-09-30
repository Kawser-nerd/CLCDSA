import java.io.*;
import java.util.*;

public class Main {
//	static Scanner in;
	static PrintWriter out;
//	static StreamTokenizer in; static int next() throws Exception {in.nextToken(); return (int) in.nval;}
	static BufferedReader in;
	
	static ArrayList<String> word;
	static boolean hasWord(String t) {
		return Collections.binarySearch(word, t) >= 0;
	}



	public static void main(String[] args) throws Exception {
//		in = new Scanner(System.in);
		out = new PrintWriter(System.out);
//		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		in = new BufferedReader(new InputStreamReader(System.in));

		int max = 0;
		BufferedReader text = new BufferedReader(new FileReader(new File("garbled_email_dictionary.txt")));
		int m = 521196;
		word = new ArrayList<String>();
		for (int i = 0; i < m; i++) {
			word.add(text.readLine());
		}


		int tests = Integer.parseInt(in.readLine());

		for (int test = 1; test <= tests; test++) {
//			System.out.println(test);
			
			String s = in.readLine();
			int n = s.length();
			int inf = n + 1;

			int[][] min = new int[n + 1][5];
			for (int[] mm : min) Arrays.fill(mm, inf);
			Arrays.fill(min[0], 0);

			for (int i = 0; i < n; i++) {
				for (int len = 1; len <= 10 && i + len <= n; len++) {
					String sub = s.substring(i, i + len);
//					out.println(sub);
					for (int lv = 0; lv < 5; lv++) if (min[i][lv] < inf) {
						int nextlv = Math.max(lv - len, 0);
						if (hasWord(sub)) {
							min[i + len][nextlv] = Math.min(min[i + len][nextlv], min[i][lv]);
						}
						for (int index = lv; index < len; index++) {
							String start = sub.substring(0, index);
							String finish = sub.substring(index + 1, len);
							nextlv = Math.max(index + 5 - len, 0);
							for (char c = 'a'; c <= 'z'; c++) if (c != sub.charAt(index)) {
								String sub2 = start + c + finish;
								if (hasWord(sub2)) {
									min[i + len][nextlv] = Math.min(min[i + len][nextlv], min[i][lv] + 1);
								}
								for (int index2 = index + 5; index2 < len; index2++) {
									String start2 = sub2.substring(0, index2);
									String finish2 = sub2.substring(index2 + 1, len);
									nextlv = Math.max(index2 + 5 - len, 0);
									for (char c2 = 'a'; c2 <= 'z'; c2++) if (c2 != sub2.charAt(index2)) {
										String sub3 = start2 + c2 + finish2;
										if (hasWord(sub3)) {
											min[i + len][nextlv] = Math.min(min[i + len][nextlv], min[i][lv] + 2);
										}
								    }
									
								}

							}
						}
					}
				}
			}
			int answ = inf;
			for (int i = 0; i < 5; i++) answ = Math.min(answ, min[n][i]);
				
			out.print("Case #" + test + ": ");
			out.println(answ);
		}

		out.close();
	}
}