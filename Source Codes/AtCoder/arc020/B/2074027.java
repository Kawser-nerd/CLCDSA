import java.util.Scanner;

class Main{
	static Scanner s=new Scanner(System.in);
	public static void main(String[]$){
		int n=s.nextInt(),k=s.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;++i)
			a[i]=s.nextInt();

		int r=n;
		for(int c1=1;c1<=10;++c1) {
			for(int c2=1;c2<=10;++c2) if(c1!=c2){
				int[]c= {c1,c2};
				int v=0;
				for(int i=0;i<n;++i) {
					if(a[i]!=c[i%2])
						++v;
				}
				r=Math.min(r,v);
			}
		}
		System.out.println(r*k);
	}
}