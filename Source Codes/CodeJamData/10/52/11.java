import java.util.*;
import java.io.*;
import java.math.*;
public class Main {

	public static void main(String[] args) {
		int tests;
		Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		tests = scanner.nextInt();
		for(int z = 1; z<=tests; z++) {
			BigInteger L = scanner.nextBigInteger();
			int ile = scanner.nextInt();
			Vector<Integer> roznice = new Vector<Integer>();
			while(ile-- > 0) {
				roznice.add(scanner.nextInt());
			}
			Collections.sort(roznice);
			int last = roznice.lastElement();
			roznice.removeElement(last);
			Vector<Integer> minodl = new Vector<Integer>(last);
			minodl.setSize(last);
			for(int i=0; i<minodl.size(); i++)
				minodl.setElementAt(Integer.MAX_VALUE, i);
			Queue<Integer> q = new LinkedList<Integer>();
			minodl.setElementAt(0, 0);
			q.add(0);
			while(q.isEmpty() == false) {
				Integer x = q.remove();
				for(Integer i: roznice) {
					int newx = x + i;
					int odl = minodl.elementAt(x) + 1;
					while(newx >= last) {
						newx -= last;
						odl--; 
					}
					if(minodl.elementAt(newx) > odl) {
						//System.out.printf("moge dojsc do %d kosztem %d\n", newx, odl);
						minodl.setElementAt(odl, newx);
						q.add(newx);
					}
				}
			}
			System.out.printf("Case #%d: ", z);
			BigInteger odleglosc = BigInteger.valueOf(last);
			BigInteger wynik = L.divide(odleglosc);
			Integer indeks = L.mod(odleglosc).intValue();
			BigInteger ileKoniec = BigInteger.valueOf(minodl.elementAt(indeks));
			if(ileKoniec.compareTo(BigInteger.valueOf(Integer.MAX_VALUE)) >= 0) {
				System.out.println("IMPOSSIBLE");
			}
			else {
				//System.out.println(wynik);
				//System.out.println(indeks);
				//System.out.println(ileKoniec);
				wynik = wynik.add(ileKoniec);
				System.out.println(wynik);
			}	
		}
	}

}
