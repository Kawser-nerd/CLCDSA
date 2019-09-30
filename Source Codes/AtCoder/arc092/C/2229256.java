import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		long a[] = new long[n];
		for(int i=0;i<n;i++)	a[i]=sc.nextLong();
		
		ArrayList<Integer> s = new ArrayList<>();
		long sum = 0;
		for(int i=0;i<n;i+=2){
			if(a[i]>0){
				sum+= a[i];
				s.add(i);
			}
		}
		if(s.size()==0){
			int idx = 0;
			for(int i=0;i<n;i+=2){
				if(a[i]>a[idx])	idx = i;
			}
			s.add(idx);
			sum = a[idx];
		}
		
		StringBuilder op = new StringBuilder();
		int cnt = 0;
		for(int i=n-1;i>=s.get(s.size()-1)+1;i--){
			cnt++;
			op.append(i+1 +"\n");
		}
		for(int i = s.size()-2;i>=0;i--){
			for(int j=0;j<(s.get(i+1)-s.get(i))/2-1;j++){
				cnt++;
				op.append(s.get(i)+3+"\n");
			}
			cnt++;
			op.append(s.get(i)+2+"\n");
		}
		for(int i=0;i<s.get(0);i++){
			cnt++;
			op.append(1+"\n");
		}
		
		ArrayList<Integer> s2 = new ArrayList<>();
		long sum2 = 0;
		for(int i=1;i<n;i+=2){
			if(a[i]>0){
				sum2+= a[i];
				s2.add(i);
			}
		}
		if(s2.size()==0){
			int idx = 1;
			for(int i=1;i<n;i+=2){
				if(a[i]>a[idx])	idx = i;
			}
			s2.add(idx);
			sum2 = a[idx];
		}
		
		StringBuilder op2 = new StringBuilder();
		int cnt2 = 0;
		for(int i=n-1;i>=s2.get(s2.size()-1)+1;i--){
			cnt2++;
			op2.append(i+1 +"\n");
		}
		for(int i = s2.size()-2;i>=0;i--){
			for(int j=0;j<(s2.get(i+1)-s2.get(i))/2-1;j++){
				cnt2++;
				op2.append(s2.get(i)+3+"\n");
			}
			cnt2++;
			op2.append(s2.get(i)+2+"\n");
		}
		for(int i=0;i<s2.get(0);i++){
			cnt2++;
			op2.append(1+"\n");
		}
		
		if(sum2>sum){
			sum = sum2;
			cnt = cnt2;
			op = op2;
		}
		System.out.println(sum);
		System.out.println(cnt);
		System.out.print(op);
		
	}
}