import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		long l =sc.nextInt();

		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		
		long[] leftSum = new long[n];
		leftSum[0]=a[0]*2;
		long[] rightSum = new long[n];
		rightSum[n-1]=(l-a[n-1])*2;
		for (int i=1;i<n;i++) {
			leftSum[i]=leftSum[i-1]+a[i]*2;
		}
		for (int i=n-2;i>=0;i--) {
			rightSum[i]=rightSum[i+1]+(l-a[i])*2;
		}
		
		
		long ans = 0;
		
		for (int i=0;i<n;i++) {
			long tmp1=0;
			long tmp2=0;
			long tmp3=0;
			int base = 0;
			//left once more
			if (i>=1) {
				base = Math.min(i-1, n-1-i);
				tmp1 += (i+1==n ? 0 : rightSum[i+1])-(i+base+1==n ? 0 : rightSum[i+base+1]);
				tmp1 += leftSum[i-1]-(i-base-2==-1 ? 0 : leftSum[i-base-2]);
				tmp1 += l-a[i];
			}
			// same number
				base = Math.min(i, n-1-i);
				tmp2 += (i+1==n ? 0 :rightSum[i+1])-(i+base+1==n ? 0 : rightSum[i+base+1]);
				tmp2 += (i-1 == -1 ? 0 :leftSum[i-1])-(i-base-1==-1 ? 0 : leftSum[i-base-1]);
				tmp2 += Math.max(a[i],l-a[i]);
			// right once more
			if (i<=n-2) {
				base = Math.min(i, n-2-i);
				tmp3 += rightSum[i+1]-(i+base+2==n ? 0 : rightSum[i+base+2]);
				tmp3 += (i-1 == -1 ? 0 : leftSum[i-1])-(i-base-1==-1 ? 0 : leftSum[i-base-1]);
				tmp3 += a[i];
			}
			
			ans = Math.max(Math.max(ans, tmp1), Math.max(tmp2, tmp3));
/*			
			if(ans==tmp1) {
				System.out.println(i+" tmp1 "+ans);
			}
			if(ans==tmp2) {
				System.out.println(i+" tmp2 "+ans);
			}
			if(ans==tmp3) {
				System.out.println(i+" tmp3 "+ans);
			}
*/
		}
		System.out.println(ans);
		
		
	}
}