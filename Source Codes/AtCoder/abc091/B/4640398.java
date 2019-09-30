import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		HashMap<String, Integer> mapplus = new HashMap<String, Integer>();
		HashMap<String, Integer> mapminus = new HashMap<String, Integer>();
		int N = sc.nextInt();
		String[] s1 = new String[N];
		for(int i = 0;i < N;i++) {
			s1[i] = sc.next();
		}
		int M = sc.nextInt();
		String[] s2 = new String[M];
		for(int i = 0;i < M;i++) {
			s2[i] = sc.next();
		}
		sc.close();
		
		//bluecard
		int plus;
		for(int i = 0;i < N ;i++) {
			plus = 0;
			plus++;
			for(int k = i + 1;k < N;k++) {
				if(s1[i].equals(s1[k])) plus++;
			}
			if(mapplus.containsKey(s1[i])) {
				if(mapplus.get(s1[i]) < plus) mapplus.put(s1[i],plus);
			}
			else mapplus.put(s1[i],plus);
		}
		
		//redcard
		int minus;
		for(int i = 0;i < M ;i++) {
			minus = 0;
			minus--;
			for(int k = i + 1;k < M;k++) {
				if(s2[i].equals(s2[k])) minus--;
			}
			if(mapminus.containsKey(s2[i])) {
				if(mapminus.get(s2[i]) > minus) mapminus.put(s2[i],minus);
			}
			else mapminus.put(s2[i],minus);
		}

		int ans = Integer.MIN_VALUE;
		for(int i = 0;i < N ;i++) {
			int sum1 = 0;
			int sum2 = 0;
			for(int k = 0;k < M;k++) {
				sum1 = mapplus.get(s1[i]);
				if(s1[i].equals(s2[k])) {
					sum2 = mapminus.get(s2[k]);	
					if(-(sum2) > sum1) sum1 = 0;
					else sum1 += sum2;
					break;
				}
			}
			if(ans < sum1) ans = sum1;
		}
		System.out.println(ans);
	}

}