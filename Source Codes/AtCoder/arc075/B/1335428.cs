using System;
delegate bool fanction(long x);
class MyData
{
    long n;
    long a, b;
    long[] h;
    public MyData(long _n, long _a, long _b, long[] _h) { n = _n; h = new long[n]; a = _a - _b; b = _b; for (int i = 0; i < n; i++) h[i] = _h[i]; }
    public bool check(long t)
    {
        long a_t = t;
	    for(int i=0;i<n;i++){
		    if (h[i] - (b*t) > 0) {
                long temp = (h[i] - b * t) / a;
			    if (((h[i] - b*t) % a) > 0) temp++;
			    a_t -= temp;
			    if (a_t < 0) return false;
		    }
	    }return true;
    }
}
class MyMain
{
    static void Main()
    {
        string[] s = System.Console.ReadLine().Trim().Split(' ');
        long n = long.Parse(s[0]), a = long.Parse(s[1]), b = long.Parse(s[2]);
        long[] ld = new long[n];
        for (int i = 0; i < n; i++) ld[i] = int.Parse(System.Console.ReadLine().Trim());
        
        long res = 0;
        binarySearch(0, 1000000000, new MyData(n, a, b, ld).check, ref res);
        System.Console.WriteLine(res);
        System.Console.ReadLine();
    }
    static void binarySearch(long l, long r,fanction f,ref long res)
    {
        if (l > r) return;
        long mid = (l + r) / 2;
        if(f(mid)){res = mid;binarySearch(l, mid - 1, f, ref res);}
        else binarySearch(mid + 1, r,f,ref res);
    }
}