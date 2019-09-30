import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		int[] scou = new int[26];
		int[] tcou = new int[26];
		Arrays.fill(scou,0);
		Arrays.fill(tcou,0);
		boolean flag = true;
		for(int i = 0; i < s.length(); i++){
			int stmp = s.charAt(i)-97;
			int ttmp = t.charAt(i)-97;
			scou[stmp]++;
			tcou[ttmp]++;
			if(scou[stmp]!=tcou[ttmp]){
				flag = false;
				break;
			}
		}
		System.out.print(flag?"Yes":"No");
	}
}