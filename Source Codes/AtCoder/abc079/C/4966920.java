import java.util.*;
public class Main {
	public static void main(String[] args) {
		C();
	}
	
	public static void A() {
		Scanner sc = new Scanner(System.in);
		Integer n = sc.nextInt();
		sc.close();
		String num = n.toString();
		if(num.charAt(1) != num.charAt(2)) {
			System.out.println("No");
			return;
		}
		char mid = num.charAt(1);
		if(mid == num.charAt(0) || mid == num.charAt(3)) {
			System.out.println("Yes");
		}
		else System.out.println("No");
	}
	
	public static void B() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		if(N==1) {
			System.out.println(1);
			return;
		}
		sc.close();
		long Li = 2;
		long Lj = 1;
		long temp;
		for(int i=2;i<N+1;i++) {
			temp = Lj;
			Lj = Li+Lj;
			Li = temp;
		}
		System.out.println(Lj);
	}
	
	// ??????????????????????????null
	// 1 + 2 - 3 =  ->  1 + 2 | -3 ..?????????
	public static void C() {
		Scanner sc = new Scanner(System.in);
		String num = sc.next();
		int[] nums = new int[4];
		for(int i=0;i<4;i++) {
			nums[i] = Character.getNumericValue(num.charAt(i)); 
		}
		ArrayList<Character> lis = calc(nums,7);
		System.out.print(nums[0]);
		for(int i=0;i<3;i++) {
			System.out.print(lis.get(i)+ "" +nums[i+1]);
		}
		System.out.println("=7");
	}
	public static ArrayList<Character> calc(int[] nums, int right) {
		return calc(nums,nums.length-1,right,new ArrayList<Character>());
	}
	public static ArrayList<Character> calc(int[] nums, int idx, int right, ArrayList<Character> lis) {
		if(idx == 0) {
			if(nums[0] == right) return lis;
			else return null;
		}
		ArrayList<Character> cand1 = calc(nums,idx-1,right+nums[idx],lis);
		if(cand1 != null) {
			cand1.add('-');
			return cand1;
		}
		ArrayList<Character> cand2 = calc(nums,idx-1,right-nums[idx],lis);
		if(cand2 != null) {
			cand2.add('+');
			return cand2;
		}
		return null;
	}
	
}