import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.next());
		int ans = 1;
		List<Integer> upper = new ArrayList<>();
		upper.add(Integer.MAX_VALUE);
		
		for(int i=0; i<N; i++){
			int w = Integer.parseInt(sc.next());
			boolean flag = true;
			for(int j=0; j<upper.size(); j++){
				if(upper.get(j) >= w){
					upper.set(j,w);
					flag = false;
					break;
				}
			}
			if(flag){
				ans++;
				upper.add(w);
			}
		}
		
		System.out.println(ans);
		
		sc.close();
	}
}