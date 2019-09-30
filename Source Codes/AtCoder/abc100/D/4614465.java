import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		Cake[] cake=new Cake[n];
		long ans=0;
		for(int i = 0; i<n; i++){
			long x = sc.nextLong();
			long y = sc.nextLong();
			long z = sc.nextLong();
			cake[i]=new Cake(x,y,z);
		}
		int[] xyz=new int[3];
		for(int i = 0; i<8; i++){
			Arrays.fill(xyz,1);
			int ii=i;
			long an=0;
			int count=0;
			while(ii>0){
				if((ii & 1)==1){
					xyz[count]*=-1;
				}
				ii>>=1;
				count++;
			}
			for(int j=0; j<n; j++){
				cake[j].x1=cake[j].x*xyz[0];
				cake[j].y1=cake[j].y*xyz[1];
				cake[j].z1=cake[j].z*xyz[2];
			}
			Arrays.sort(cake,Comparator.comparing(Cake::getSum).reversed());
			for(int k=0; k<m; k++){
				an+=cake[k].getSum();
			}
			ans=Math.max(ans,an);
		}
		System.out.println(ans);
	}
	static class Cake{
		long x;
		long y;
		long z;
		long x1;
		long y1;
		long z1;
		public Cake(long x,long y,long z){
			this.x=x;
			this.y=y;
			this.z=z;
		}
		public long getSum(){
			return	this.x1+this.y1+this.z1;
		}
	}
}