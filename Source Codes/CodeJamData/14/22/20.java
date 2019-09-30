import java.util.Scanner;

public class B
{
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);

		int tc = in.nextInt();

		for(int t = 1 ; t <= tc ; t++)
		{
			long a = in.nextInt();
			long b = in.nextInt();
			long c = in.nextInt();

			long [][][][] dp = new long[40][2][2][2];
			dp[35][1][1][1] = 1;

			long res = 0;

			for(int bit = 35 ; bit >= 0 ; bit--)
				for(int ae = 0 ; ae < 2 ; ae++)
					for(int be = 0 ; be < 2 ; be++)
						for(int ce = 0 ; ce < 2 ; ce++)
							if(dp[bit][ae][be][ce] != 0)
							{
								//1 1
								if(ae == 0 || ((1L<<bit) & a) != 0)
									if(be == 0 || ((1L<<bit) & b) != 0)
										if(ce == 0 || ((1L<<bit) & c) != 0)
										{
											int nae = ae;
											int nbe = be;
											int nce = ce;

											if(bit != 0)
												dp[bit-1][nae][nbe][nce] += dp[bit][ae][be][ce];
											else if(nae + nbe + nce == 0)
												res += dp[bit][ae][be][ce];


										}
								//1 0
								if(ae == 0 || ((1L<<bit) & a) != 0)
								{
									int nae = ae;
									int nbe = be;
									if(((1L<<bit) & b) != 0)
										nbe = 0;
									int nce = ce;
									if(((1L<<bit) & c) != 0)
										nce = 0;

									if(bit != 0)
										dp[bit-1][nae][nbe][nce] += dp[bit][ae][be][ce];
									else if(nae + nbe + nce == 0)
										res += dp[bit][ae][be][ce];
								}

								//0 1
								if(be == 0 || ((1L<<bit) & b) != 0)
								{
									int nae = ae;
									if(((1L<<bit) & a) != 0)
										nae = 0;
									int nbe = be;
									int nce = ce;
									if(((1L<<bit) & c) != 0)
										nce = 0;

									if(bit != 0)
										dp[bit-1][nae][nbe][nce] += dp[bit][ae][be][ce];
									else if(nae + nbe + nce == 0)
										res += dp[bit][ae][be][ce];
								}

								//0 0
								{
									int nae = ae;
									if(((1L<<bit) & a) != 0)
										nae = 0;
									int nbe = be;
									if(((1L<<bit) & b) != 0)
										nbe = 0;
									int nce = ce;
									if(((1L<<bit) & c) != 0)
										nce = 0;

									if(bit != 0)
										dp[bit-1][nae][nbe][nce] += dp[bit][ae][be][ce];
									else if(nae + nbe + nce == 0)
										res += dp[bit][ae][be][ce];
								}

							}

			System.out.println("Case #"+t+": "+res);
		}
	}
}

