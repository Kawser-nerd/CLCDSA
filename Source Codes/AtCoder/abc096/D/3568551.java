import java.util.*;

class Main{
	public static void main(String[] args){
		int p=0;
		Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        
        List<Integer> arr = Main.sieve(55555);
        List<Integer> arr2 = new ArrayList<Integer>();
        for(int i = 0; i < arr.size(); i++) {
        	if(arr.get(i) % 5 == 1) arr2.add(arr.get(i));
        }
        for(int i = 0; i < N; i++) {
        	System.out.print(arr2.get(i) + " ");
        }
	}

	static List<Integer> sieve(int N) {
		List<Integer> arr = new ArrayList<Integer>();
		arr.add(2);
		for(int i = 3; i < N; i++) {
			boolean flag = true;
			
			int k = 0;
			while(flag && k < arr.size()) {
				if(i % arr.get(k) == 0) {
					flag = false;
				}
				k++;
			}
			if(flag) {
				arr.add(i);
			}
		}
		return arr;
	}
}