import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class P1 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("p1.in"));
		String line = "";
		int t = Integer.parseInt(br.readLine());
		FileWriter out = new FileWriter("p1.out");
		for (int i=0; i<t; i++) {
			int n = Integer.parseInt(br.readLine());
			String v1 = br.readLine();
			String v2 = br.readLine();
			
			String[] vv1 = v1.split("\\s+"); 
			String[] vv2 = v2.split("\\s+");
			
			List<Long> iv1 = s2l(vv1);
			List<Long> iv2 = s2l(vv2);

			Collections.sort(iv1);
			Collections.sort(iv2);
			if (iv1.size()!=iv2.size())
				System.out.println("Oops!");
			long res = 0;
			for (int j=0; j<iv1.size(); j++) {
				System.out.println(iv1.get(j) +" * " + iv2.get(iv1.size()-1-j));
				res += iv1.get(j) * iv2.get(iv1.size()-1-j);
			}
			
			out.write("Case #" + (i+1) + ": " + res + "\n");
			System.out.println(res);
		}
		br.close();
		out.close();
	}

	private static List<Long> s2l(String[] vv1) {
		List<Long> ret = new ArrayList<Long>(vv1.length);
		for (int i=0; i<vv1.length; i++)
			ret.add(Long.parseLong(vv1[i]));
		return ret;
	}
}
