import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class A {

	public static void main(String[] args) throws IOException {

		BufferedReader buffer = new BufferedReader(new InputStreamReader(
				System.in));
		String entrada = buffer.readLine();
		String ns[] = entrada.split(" ");
		int l = Integer.parseInt(ns[0]);
		int d = Integer.parseInt(ns[1]);
		int n = Integer.parseInt(ns[2]);

		String palavras[] = new String[d + 1];
		for (int i = 0; i < d; i++) {
			palavras[i] = buffer.readLine();
		}

		for (int k = 1; k <= n; k++) {
			List<Set<Character>> conjuntosAceitaveis = new ArrayList<Set<Character>>();
			for (int i = 0; i < l; i++) {
				conjuntosAceitaveis.add(new HashSet<Character>());
			}
			String expressao = buffer.readLine();
			int pt = 0;
			for (int i = 0; i < l; i++) {
				if (expressao.charAt(pt) == '(') {
					for (pt++; expressao.charAt(pt) != ')'; pt++) {
						conjuntosAceitaveis.get(i).add(expressao.charAt(pt));
					}
					pt++;
				} else {
					conjuntosAceitaveis.get(i).add(expressao.charAt(pt));
					pt++;
				}
			}
			int cont = 0;
			for (int i = 0; i < d; i++) {
				boolean pode = true;
				for (int j = 0; j < l; j++) {
					if (!conjuntosAceitaveis.get(j).contains(
							palavras[i].charAt(j))) {
						pode = false;
						break;
					}
				}
				if (pode)
					cont++;
			}
			System.out.println("Case #" + k + ": " + cont);
		}

	}

}
