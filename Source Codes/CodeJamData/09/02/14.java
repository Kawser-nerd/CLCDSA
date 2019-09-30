import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class B {

	static int h, w;
	static int altura[][];
	static int id[][];
	static List<Integer> basins;
	
	static String nome = "abcdefghijklmnopqrstuvwxyz";
	
	static int identifica(int i, int j) {
		if (id[i][j]!=-1) {
			return id[i][j];
		}
		boolean n=false,ww=false,e=false,s=false;
		boolean found=false;
		int alt = altura[i][j];
		if (i>0) {
			if (alt>altura[i-1][j]) {
				n=found=true;
				alt = altura[i-1][j];
			}
		}
		if (j>0) {
			if (alt>altura[i][j-1]) {
				ww=found=true;
				alt = altura[i][j-1];
			}
		}
		if ((j+1)<w) {
			if (alt>altura[i][j+1]) {
				e=found=true;
				alt = altura[i][j+1];
			}
		}
		if ((i+1)<h) {
			if (alt>altura[i+1][j]) {
				s=found=true;
				alt = altura[i+1][j];
			}
		}
		if (!found) {
			id[i][j] = 1000*i+j;
			basins.add(id[i][j]);
		}
		else if (s) {
			id[i][j] = identifica(i+1, j);
		}
		else if (e) {
			id[i][j] = identifica(i, j+1);
		}
		else if (ww) {
			id[i][j] = identifica(i, j-1);
		}
		else if (n) {
			id[i][j] = identifica(i-1, j);
		}
		
		
		
		return id[i][j];
	}

	public static void main(String[] args) throws IOException {

		BufferedReader buffer = new BufferedReader(new InputStreamReader(
				System.in));
		String entrada = buffer.readLine();
		int t = Integer.parseInt(entrada);

		for (int k = 1; k <= t; k++) {
			entrada = buffer.readLine();
			h = new Integer(entrada.split(" ")[0]);
			w = new Integer(entrada.split(" ")[1]);

			altura = new int[h + 1][w + 1];
			id = new int[h + 1][w + 1];
			for (int i = 0; i < h; i++) {
				String linha[] = buffer.readLine().split(" ");
				for (int j = 0; j < w; j++) {
					altura[i][j] = new Integer(linha[j]);
					id[i][j]=-1;
				}
			}
			basins = new ArrayList<Integer>();
			for (int i=0;i<h;i++) {
				for (int j=0;j<w;j++) {
					identifica(i,j);
				}
			}
			
			Collections.sort(basins);
			Map<Integer, Character> basinCode = new HashMap<Integer, Character>();
			int pt=0;
			
			System.out.println("Case #"+k+":");
			for (int i=0;i<h;i++) {
				for (int j=0;j<w;j++) {
					if (j>0) System.out.print(" ");
					if (!basinCode.containsKey(id[i][j])) {
						basinCode.put(id[i][j], nome.charAt(pt++));
					}
					System.out.print(basinCode.get(id[i][j]));
				}
				System.out.println();
			}
		}

	}

}
