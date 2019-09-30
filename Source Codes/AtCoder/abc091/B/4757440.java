import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		String s[] = new String[x];
		for(int i = 0; i < x; i++){
			s[i] = sc.next();
		}
		int n = sc.nextInt();
		String t[] = new String[n];
		for(int i = 0; i < n; i++){
			t[i] = sc.next();
		}
		int num = 0;
		int sco = 0;
		for(int i = 0; i < x; i++){
			for(int k = 0; k < x; k++){
				if(s[i].equals(s[k]))num++;
			}
			for(int j = 0; j < n; j++){
				if(s[i].equals(t[j]))num--;
			}
			if(num > sco)sco = num;
			num = 0;
		}
		System.out.println(sco > 0? sco : 0);
	}
}