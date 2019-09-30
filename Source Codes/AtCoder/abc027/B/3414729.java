import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n=scanner.nextInt();
		int a[]=new int[n];
		Set<Point>set=new HashSet<>();
		int sum=0;
		for(int i=0;i<n;i++) {
			a[i]=scanner.nextInt();
			sum+=a[i];
		}
		if(sum%n!=0) {
			System.out.println(-1);
			return;
		}
		int ave=sum/n;
		for(int i=0;i<n-1;i++) {
			if(a[i]==ave)continue;
			a[i+1]+=a[i]-ave;
			a[i]=ave;
			set.add(new Point(i,i+1));
		}
		
		System.out.println(set.size());
	}
}

class Point {
	int x, y;

	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + x;
		result = prime * result + y;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Point other = (Point) obj;
		if (x != other.x)
			return false;
		if (y != other.y)
			return false;
		return true;
	}
}