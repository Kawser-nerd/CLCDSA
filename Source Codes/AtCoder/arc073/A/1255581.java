import java.util.*;

public class Main {
	public static void main(String[] args){

		//?????????
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt(); //??
		int T = sc.nextInt(); //??
		
		ArrayList<Integer> tn = new ArrayList<Integer>(); //????
		for(int i = 0; i < N; i++){
			tn.add(sc.nextInt());
		}

		int sumShowerTime = T;
		int endShower = T;
		for(int i=1; i<tn.size(); i++){
			int term = tn.get(i) - tn.get(i-1);
			if(term > T){
				sumShowerTime += T;
			} else{
				sumShowerTime += term;
			}
			if(endShower < tn.get(i)+term){
				endShower = tn.get(i)+term;
			}
		}
		
		System.out.println(sumShowerTime);
		
		return;
	}
}