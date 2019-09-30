import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.next());
		int M = Integer.parseInt(sc.next());
		List<Integer[]> needs = new LinkedList<>();
		for(int i=0; i<M; i++){
			int a = Integer.parseInt(sc.next());
			int b = Integer.parseInt(sc.next());
			Integer[] need = {a,b};
			needs.add(need);
		}
		
		needs.sort((a,b) -> Integer.compare(a[1], b[1]));
		
		int ans = 0; 
		int pos;
		while(needs.size()>0){
			pos = needs.get(0)[1];
			ans++;
			Iterator<Integer[]> iterator = needs.iterator();
			while(iterator.hasNext()){
				Integer[] need = iterator.next();
				if(need[0] < pos && need[1] >= pos)
					iterator.remove();
			}
		}
		
		System.out.println(ans);
		
		sc.close();
	}
}