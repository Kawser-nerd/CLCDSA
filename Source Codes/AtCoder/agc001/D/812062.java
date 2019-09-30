import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		ArrayList<Integer> odd = new ArrayList<>();
		ArrayList<Integer> even = new ArrayList<>();
		for(int i=0; i<M; i++) {
			int A = sc.nextInt();
			if(A%2==0)
				even.add(A);
			else
				odd.add(A);
		}
		
		if(odd.size()>2) {
			System.out.println("Impossible");
		} else {
			ArrayList<Integer> list = new ArrayList<>();
			if(odd.size()>0)
				list.add(odd.get(0));
			list.addAll(even);
			if(odd.size()>1)
				list.add(odd.get(1));

			printList(list);
			
			if(list.size()==1) {
				if(list.get(0)>1) {
					list.set(0, list.get(0)-1);
					list.add(1);
				}
			} else {
				list.set(0, list.get(0)-1);
				list.set(list.size()-1, list.get(list.size()-1)-1);
				list.add(1, 2);
				if(list.get(0)==0)
					list.remove(0);
				if(list.get(list.size()-1)==0)
					list.remove(list.size()-1);
			}
			
			System.out.println(list.size());
			
			printList(list);
		}
		
		sc.close();
	}
	
	static void printList(ArrayList<Integer> list) {
		for(int i=0; i<list.size(); i++)
			System.out.print(list.get(i) + (i==list.size()-1 ? "\n" : " "));
	}
}