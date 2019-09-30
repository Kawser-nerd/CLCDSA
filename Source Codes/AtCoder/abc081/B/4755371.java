import java.util.*;

public class Main {

	public static void main(String[] args) {
		try(Scanner scan = new Scanner(System.in);){
			int count = 0;
			List<Integer> list = new ArrayList<Integer>();
			int N = Integer.parseInt(scan.next());
			for(int i=0; i< N ; i++) {
				list.add(Integer.parseInt(scan.next()));
			}
			out:while(true) {
				for(int j = 0; j<N ; j++) {
					int elm = list.get(j);
					if(elm % 2 == 1) {
						System.out.print(count);
						break out;
					}else {
						list.set(j, elm/2);
					}
				}
				count++;
			}		
		}		
	}
}