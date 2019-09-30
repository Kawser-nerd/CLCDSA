import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {

		//s????????????????-1???
		//????????s????????????????????????????????????

		String s = sc.next();
		boolean[] alphabet = new boolean[26];
		for (int i=0; i<s.length(); i++) {
			alphabet[s.charAt(i)-'a'] = true;
		}

		if (s.length() < 26) {
			for (int i=0; i<26; i++) {
				if (alphabet[i] == false) {
					System.out.println(s+(char)(i+'a'));
					return;
				}
			}
		}
		else {
			//nextpermutation
			String temp = nextPermutation(s);
			
			if (temp.equals("Final")) {
				System.out.println(-1);
				return;
			}
			
			for (int i=0; i<s.length(); i++) {
				if (s.charAt(i) != temp.charAt(i)) {
					System.out.println(temp.substring(0,i+1));
					return;
				}
			}
			
		}



	}
	
	static String nextPermutation (String s) {
		
		ArrayList<Character> list = new ArrayList<>();
		for (int i=0; i<s.length(); i++) list.add(s.charAt(i));
		
		
		int pivotPos = -1;
		char pivot = 0;
		
		for (int i=list.size()-2; i>=0; i--) {
			if (list.get(i) < list.get(i+1)) {
				pivotPos = i;
				pivot = list.get(i);
				break;
			}
		}
		
		if (pivotPos==-1 && pivot==0) return "Final";
		
		int L = pivotPos+1, R = list.size()-1;
		int minPos = -1;
		char min = Character.MAX_VALUE;
		for (int i=R; i>=L; i--) {
			if (pivot < list.get(i)) {
				if (list.get(i) < min) {
					min = list.get(i);
					minPos = i;
				}
			}
		}
		
		Collections.swap(list, pivotPos, minPos);
		
		Collections.sort(list.subList(L, R+1));
		
		StringBuilder sb = new StringBuilder();
		for (int i=0; i<list.size(); i++) sb.append(list.get(i));

		return sb.toString();
		
	}
	

}