import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		long H=sc.nextLong();
		long[][] katana=new long[N][2];
		long max=0;
		for(int i=0; i<N; i++) {
			katana[i][0]=sc.nextLong();
			max=Math.max(katana[i][0],max);
			katana[i][1]=sc.nextLong();
		}
		int cnt=0;
		for(int i=0; i<N; i++) {
			if(katana[i][1]>max) {
				cnt++;
			}
		}
		if(cnt>0) {
			int tmp=0;
			long[][] nage=new long[cnt][2];
			for(int i=0; i<N; i++) {
				if(katana[i][1]>max) {
					nage[tmp][0]=katana[i][1];
					nage[tmp][1]=0;
					tmp++;
				}
			}
			quick_sort(nage,0,tmp-1);
			long[][] cp=new long[tmp][2];
			cp[0][0]=nage[tmp-1][0];
			cp[0][1]=nage[tmp-1][0];
			for(int i=1; i<tmp; i++) {
				cp[i][0]=nage[tmp-1-i][0];
				cp[i][1]=cp[i-1][1]+cp[i][0];
			}

			if(H>=cp[tmp-1][1]) {
				//System.out.println(cp[tmp-1][1]);
				H-=cp[tmp-1][1];
				long kaisu=(H+max-1)/max;
				System.out.println(kaisu+tmp);
			}
			else {
				long[] sm=new long[tmp];
				for(int i=0; i<tmp; i++) {
					sm[i]=cp[i][1];
				}
				long kaisu=lowerBound(sm,H);
				System.out.println(kaisu+1);
			}
		}
		else {
			System.out.println((H+max-1)/max);
		}

	}
	static void quick_sort(long[][] d, int left, int right) {
		if (left>=right) {
			return;
		}
		long p = d[(left+right)/2][0];
		int l = left, r = right;
		long tmp,tmp1,tmp2;
		while(l<=r) {
			while(d[l][0] < p) { l++; }
			while(d[r][0] > p) { r--; }
			if (l<=r) {
				tmp = d[l][0]; d[l][0] = d[r][0]; d[r][0] = tmp;
				tmp1=d[l][1]; tmp2=d[r][1]; d[l][1]=tmp2; d[r][1]=tmp1;
				l++; r--;
			}
		}
		quick_sort(d, left, r);
		quick_sort(d, l, right);
	}
	public static final int lowerBound(final long[] arr, final long value) {
		int low = 0;
		int high = arr.length;
		int mid;
		while (low < high) {
			mid = ((high - low) >>> 1) + low;    //(low + high) / 2 (?????????)
			if (arr[mid] < value) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		if(low<arr.length) {
			return low;
		}
		else {
			return -1;
		}
	}
}