class P
{
    static void Main()
    {
        long a ;
        int k;
        scanf("%ld %d", out a, out k);
        if (k == 0)
        {
            printf((2000000000000 - a).ToString() + "\n");
            return;
        }
        int c = 0;
        for (c = 1; ; c++)
        {
            a += 1 + k * a;
            if (a >= 2000000000000)
                break;
        }
        printf(c.ToString() + "\n");
    }
    [System.Runtime.InteropServices.DllImport("msvcrt.dll")]
    private static extern int scanf(string format, out long l, out int k);
[System.Runtime.InteropServices.DllImport("msvcrt.dll")]
    private static extern void printf(string s);
}