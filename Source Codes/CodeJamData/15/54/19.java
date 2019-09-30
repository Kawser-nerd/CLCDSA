import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/D-small.in"))));

		String output = "";
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= t; i++) {
			int p = sc.nextInt();
			HashMap<Integer, Integer> elements = new HashMap<Integer, Integer>();
			HashMap<Integer, Integer> newElements = new HashMap<Integer, Integer>();
			ArrayList<Integer> finalSet = new ArrayList<Integer>();
			int[] e = new int[p];
			int[] f = new int[p];
			for (int j = 0; j < p; j++)
				e[j] = sc.nextInt();
			for (int j = 0; j < p; j++)
				f[j] = sc.nextInt();
			for (int j = 0; j < p; j++) {
				elements.put(e[j], f[j]/f[0]);
				newElements.put(e[j], 0);
			}
			int numZeroes = 0;
			while (1<<numZeroes < f[0])
				numZeroes++;
			for (int j = 0; j < numZeroes; j++)
				finalSet.add(0);
			newElements.put(0, 1);
			elements.put(0, 0);
			boolean didFill = true;
			while (didFill) {
				didFill = false;
				for (int elem : e) {
					int freq = elements.get(elem);
					if (freq > 0) {
						finalSet.add(elem);
						for (int element : e) {
							if (elements.containsKey(element+elem)) {
								elements.put(element+elem, elements.get(element+elem)-newElements.get(element));
							}
						}
						for (int j = p-1; j >= 0; j--) {
							int element = e[j];
							if (elements.containsKey(element+elem)) {
								newElements.put(element+elem, newElements.get(element+elem)+newElements.get(element));
							}
						}
						didFill = true;
						break;
					}
				}
			}
			String setPrintout = ""+finalSet.get(0);
			for (int j = 1; j < finalSet.size(); j++)
				setPrintout += " " + finalSet.get(j);
			output += "Case #" + i + ": " + setPrintout + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/D-small.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}